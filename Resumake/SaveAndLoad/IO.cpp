#include "IO.h"

#include <QJsonValue>
#include <QFile>
IO::IO(){
}


QString IO::skillsToString(QVector<Skill> skills){
    QString s = "";
    for(int i = 0 ; i < skills.size(); i ++){
        Skill skill = skills.at(i);
        s.append(skill.getSkill());
        if(i != skills.size() -1)
            s.append(", ");
    }
    return s;
}


QVector<Skill> IO::stringToSkills(QString s){
    QVector<Skill> skills;
    auto sl = s.split(",");
    for(auto st: sl){
        st = st.trimmed();

        Skill s;
        s.setSkill(st);
        skills.push_back(s);
    }

    return skills;
}


Employment IO::createExperience(QString position, QString location, QString date, QString description, QString type){
    Employment experience;
    experience.setPosition(position);
    experience.setLocation(location);
    experience.setDate(date);
    experience.setDescription(description);
    experience.setType(type);
    return experience;
}

QString IO::saveResume(Resume * resume, int state){

    auto personalInfo = resume->getPersonalInfo();

    IO::resInfo.insert("State", QJsonValue(state));

    IO::personalInfo.insert("Name", QJsonValue(personalInfo.getName()));
    IO::personalInfo.insert("Email", QJsonValue(personalInfo.getEmail()));
    IO::personalInfo.insert("Phone", QJsonValue(personalInfo.getPhoneNumber()));
    IO::personalInfo.insert("Description", QJsonValue(personalInfo.getDescription()));
    IO::resInfo.insert("Personal Info", IO::personalInfo);

    auto education = resume->getEducation();

    IO::educationInfo.insert("Institution", QJsonValue(education.getInstitutionName()));
    IO::educationInfo.insert("Enrollment", QJsonValue(education.getEnrollmentDate()));
    IO::educationInfo.insert("Graduation", QJsonValue(education.getGraduationDate()));
    IO::educationInfo.insert("Description", QJsonValue(education.getDescription()));
    IO::resInfo.insert("Education", IO::educationInfo);

    auto experiences = resume->getExperiences();

    for(int i = 0; i < experiences.length(); i ++){
        auto experience = experiences[i];
        IO::experienceInfo[i].insert("Position", QJsonValue(experience.getPosition()));
        IO::experienceInfo[i].insert("Location", QJsonValue(experience.getLocation()));
        IO::experienceInfo[i].insert("Date", QJsonValue(experience.getDate()));
        IO::experienceInfo[i].insert("Description", QJsonValue(experience.getDescription()));
        QString s;
        if(i == 0){
           s = "Experience1";
        }else if(i == 1){
           s = "Experience2";
        }else{
            s = "Experience3";
        }

        IO::resInfo.insert(s, IO::experienceInfo[i]);
    }

    auto skills = resume->getSkills();
    QString skill = skillsToString(skills);

    IO::skillInfo.insert("Skill", QJsonValue(skill));
    IO::resInfo.insert("Skills", IO::skillInfo);

    QFile jsonFile(IO::DEFAULT_LOAD_PATH);
    jsonFile.open(QFile::WriteOnly);

    QJsonDocument doc(resInfo);
    jsonFile.write(doc.toJson());
    jsonFile.close();

    return DEFAULT_LOAD_PATH;
}
int IO::loadResume(Resume * resume){
    QFileInfo savedFile(DEFAULT_LOAD_PATH);

    if(!savedFile.exists() || !savedFile.isFile()){
        return -1;
    }


    QFile jsonFile(DEFAULT_LOAD_PATH);
    jsonFile.open(QFile::ReadOnly);
    auto doc = QJsonDocument().fromJson(jsonFile.readAll());
    jsonFile.close();

    int state = doc["State"].toInt();


    auto personalInfo = doc["Personal Info"];
    resume->updatePersonalInfo(personalInfo["Name"].toString(), personalInfo["Phone"].toString(), personalInfo["Email"].toString(),
            personalInfo["Description"].toString(), "", "", "");

    auto education = doc["Education"];
    resume->setEducation(education["Institution"].toString(), education["Description"].toString(),
            education["Enrollment"].toString(), education["Graduation"].toString());

    auto skills = stringToSkills(doc["Skills"]["Skill"].toString());
    resume->setSkills(skills);

    auto exp = doc["Experience1"];
    auto e1 = createExperience(exp["Position"].toString(), exp["Location"].toString(), exp["Date"].toString(), exp["Description"].toString());

    exp = doc["Experience2"];
    auto e2 = createExperience(exp["Position"].toString(), exp["Location"].toString(), exp["Date"].toString(), exp["Description"].toString());

    exp = doc["Experience3"];
    auto e3 = createExperience(exp["Position"].toString(), exp["Location"].toString(), exp["Date"].toString(), exp["Description"].toString());

    QVector<Employment> es = {e1, e2, e3};
    resume->setExperiences(es);

    resume->setFormatter(0);


    return state;
}
