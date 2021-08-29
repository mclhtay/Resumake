#include "resume.h"

Resume::Resume()
{
    for(int i = 0; i < 3; i ++){
        Employment emp;
        experiences.push_back(emp);
    }
}


Education Resume::getEducation(){
    return Resume::education;
}
QVector<Skill> Resume::getSkills(){
    return Resume::skills;
}
QVector<Employment> Resume::getExperiences(){
    return Resume::experiences;
}
PersonalInfo Resume::getPersonalInfo(){
    return Resume::personalInfo;
}


// as of now, only requires name, phone and email.
void Resume::updatePersonalInfo(QString name, QString phone, QString email, QString description = "", QString linkedIn=" ", QString github=" ", QString website=" "){
    personalInfo.setName(name);
    personalInfo.setPhoneNumber(phone);
    personalInfo.setEmail(email);
    personalInfo.setLinkedIn(linkedIn);
    personalInfo.setGithub(github);
    personalInfo.setWebsite(website);
    personalInfo.setDescription(description);
}

// as of now, only requires name, date, and description
void Resume::setEducation(QString name, QString description, QString date, QString gdate){
    education.setInstitutionName(name);
    education.setEnrollmentDate(date);
    education.setDescription(description);
    education.setGraduationDate(gdate);
}


// as of now, only supports employment experience
void Resume::setExperiences(QVector<Employment> emp){
    experiences.clear();
    for(auto exp: emp){
        experiences.push_back(exp);
    }
}

// currently do not support skills
void Resume::setSkills(QVector<Skill> sk){
    skills.clear();
    for(auto skill: sk){
        skills.push_back(skill);
    }

}

void Resume::setFormatter(int id){
    Resume::formatterId = id;
}

int Resume::getFormatter(){
    return Resume::formatterId;
}

void Resume::reset(){
    personalInfo.reset();
    education.reset();
    experiences.clear();
    skills.clear();
    formatterId = 0;
    for(int i = 0; i < 3; i ++){
        Employment emp;
        experiences.push_back(emp);
    }
}
