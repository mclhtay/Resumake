#include "educationandexperiencepageadapter.h"

EducationAndExperiencePageAdapter::EducationAndExperiencePageAdapter(): PageAdapter()
{

}

QString EducationAndExperiencePageAdapter::validateInput(QVector<QString> userInputs){
    int error = -1;
    if(!ec->checkInstitution(userInputs[0]) || !ec->checkInstitution(userInputs[4])){
        error = 5;
    }
    else if(!ec->checkLength(userInputs[1]) || !ec->checkLength(userInputs[5])){
        error = 6;
    }
    else if(!ec->checkDate(userInputs[2]) || ! ec->checkDate(userInputs[6]) || !ec->checkDate(userInputs[7])){
        error = 7;
    }
    else if(!ec->checkDescription(userInputs[3])){
        error = 8;
    }

    return error == -1 ? "": em->getErrorMessage(error);

}

Employment EducationAndExperiencePageAdapter::createExperience(QString position, QString location, QString date, QString description, QString type="Employment"){
    Employment experience;
    experience.setPosition(position);
    experience.setLocation(location);
    experience.setDate(date);
    experience.setDescription(description);
    experience.setType(type);
    return experience;
}

void EducationAndExperiencePageAdapter::updateResume(Resume * resume, QVector<QString> userInputs){
    QVector<Employment> experiences = resume->getExperiences();
    Employment emp = createExperience(userInputs[0],userInputs[1], userInputs[2],userInputs[3], "Employment");
    experiences.replace(0, emp);
    resume->setExperiences(experiences);
    resume->setEducation(userInputs[4], userInputs[5], userInputs[6], userInputs[7]);
}
QVector<QString> EducationAndExperiencePageAdapter::getStoredInputs(Resume * resume){
    QVector<QString> savedInputs;
    auto exp = resume->getExperiences().at(0);
    if(exp.getPosition() != NULL){
        savedInputs.push_back(exp.getPosition());
    }else{
        savedInputs.push_back("");
    }

    if(exp.getLocation() != NULL){
        savedInputs.push_back(exp.getLocation());
    }else{
        savedInputs.push_back("");
    }

    if(exp.getDate() != NULL){
        savedInputs.push_back(exp.getDate());
    }else{
        savedInputs.push_back("");
    }

    if(exp.getDescription() != NULL){
        savedInputs.push_back(exp.getDescription());
    }else{
        savedInputs.push_back("");
    }


    Education edu = resume->getEducation();
    if(edu.getInstitutionName() != NULL){
        savedInputs.push_back(edu.getInstitutionName());
    }else{
        savedInputs.push_back("");
    }

    if(edu.getDescription() != NULL){
        savedInputs.push_back(edu.getDescription());
    }else{
        savedInputs.push_back("");
    }

    if(edu.getEnrollmentDate() != NULL){
        savedInputs.push_back(edu.getEnrollmentDate());
    }else{
        savedInputs.push_back("");
    }

    if(edu.getGraduationDate() != NULL){
        savedInputs.push_back(edu.getGraduationDate());
    }else{
        savedInputs.push_back("");
    }
    return savedInputs;
}
