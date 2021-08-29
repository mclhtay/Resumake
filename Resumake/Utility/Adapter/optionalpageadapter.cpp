#include "optionalpageadapter.h"

OptionalPageAdapter::OptionalPageAdapter(): PageAdapter()
{

}

Employment OptionalPageAdapter::createExperience(QString position, QString location, QString date, QString description, QString type="Employment"){
    Employment experience;
    experience.setPosition(position);
    experience.setLocation(location);
    experience.setDate(date);
    experience.setDescription(description);
    experience.setType(type);
    return experience;
}


QString OptionalPageAdapter::validateInput(QVector<QString> userInputs){
    bool exp1 = false, exp2 = false;

    for(int i = 0; i < 4; i ++){
        if(userInputs.at(i).length() != 0){
            exp1 = true;
            break;
        }
    }

    for(int i = 4; i < 8; i ++){
        if(userInputs.at(i).length() != 0){
            exp2 = true;
            break;
        }
    }

    int error = -1;
    if(exp1){
        if(!ec->checkInstitution(userInputs[0])){
            error = 5;
        }
        else if(!ec->checkLength(userInputs[1]) ){
            error = 6;
        }
        else if(!ec->checkDate(userInputs[2])){
            error = 7;
        }
        else if(!ec->checkDescription(userInputs[3])){
            error = 8;
        }
    }else if(exp2){
        if(!ec->checkInstitution(userInputs[4]) ){
            error = 5;
        }
        else if(!ec->checkLength(userInputs[5]) ){
            error = 6;
        }
        else if(!ec->checkDate(userInputs[6]) ){
            error = 7;
        }
        else if(!ec->checkDescription(userInputs[7])){
            error = 8;
        }
    }
    return error == -1 ? "": em->getErrorMessage(error);

}

void OptionalPageAdapter::updateResume(Resume * resume, QVector<QString> userInputs){
    auto experiences = resume->getExperiences();
    Employment emp1 = createExperience(userInputs[0],userInputs[1], userInputs[2],userInputs[3], "Employment");
    Employment emp2 = createExperience(userInputs[4],userInputs[5], userInputs[6],userInputs[7], "Employment");
    experiences.replace(1, emp1);
    experiences.replace(2, emp2);
    resume->setExperiences(experiences);
}
QVector<QString> OptionalPageAdapter::getStoredInputs(Resume * resume){
    QVector<QString> savedInputs;
    auto emp1 = resume->getExperiences().at(1);
    auto emp2 = resume->getExperiences().at(2);


    if(emp1.getPosition() != NULL){
        savedInputs.push_back(emp1.getPosition());
    }else{
        savedInputs.push_back("");
    }

    if(emp1.getLocation() != NULL){
        savedInputs.push_back(emp1.getLocation());
    }else{
        savedInputs.push_back("");
    }

    if(emp1.getDate() != NULL){
        savedInputs.push_back(emp1.getDate());
    }else{
        savedInputs.push_back("");
    }

    if(emp1.getDescription() != NULL){
        savedInputs.push_back(emp1.getDescription());
    }else{
        savedInputs.push_back("");
    }

    if(emp2.getPosition() != NULL){
        savedInputs.push_back(emp2.getPosition());
    }else{
        savedInputs.push_back("");
    }

    if(emp2.getLocation() != NULL){
        savedInputs.push_back(emp2.getLocation());
    }else{
        savedInputs.push_back("");
    }

    if(emp2.getDate() != NULL){
        savedInputs.push_back(emp2.getDate());
    }else{
        savedInputs.push_back("");
    }

    if(emp2.getDescription() != NULL){
        savedInputs.push_back(emp2.getDescription());
    }else{
        savedInputs.push_back("");
    }

    return savedInputs;
};
