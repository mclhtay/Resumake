#include "personalinfopageadapter.h"

PersonalInfoPageAdapter::PersonalInfoPageAdapter(): PageAdapter()
{

}
QString PersonalInfoPageAdapter::validateInput(QVector<QString> userInputs){
    int error = -1;

    if(!ec->checkName(userInputs[0])){
        error = 0;
    }
    else if(!ec->checkEmail(userInputs[1])){
        error = 1;
    }
    else if(!ec->checkPhone(userInputs[2])){
        error =2;
    }else if(!ec->checkLongString(userInputs[3]) ){
        error = 3;
    }else if(!ec->checkLongString(userInputs[4])){
        error = 4;
    }

    return error == -1 ? "": em->getErrorMessage(error);
}
void PersonalInfoPageAdapter::updateResume(Resume * resume, QVector<QString> userInputs){
    resume->updatePersonalInfo(userInputs[0], userInputs[1], userInputs[2], userInputs[3], "", "", "");

    auto sl = userInputs[4].split(",");
    QVector<Skill> skills;

    for(auto st: sl){
        st = st.trimmed();

        Skill s;
        s.setSkill(st);
        skills.push_back(s);
    }

    resume->setSkills(skills);

}
QVector<QString> PersonalInfoPageAdapter::getStoredInputs(Resume * resume){
    QVector<QString> savedInputs;

    PersonalInfo p = resume->getPersonalInfo();
    if(p.getName() != NULL){
        savedInputs.push_back(p.getName());
    }else{
        savedInputs.push_back("");
    }

    if(p.getPhoneNumber() != NULL){
        savedInputs.push_back(p.getPhoneNumber());
    }else{
        savedInputs.push_back("");
    }

    if(p.getEmail() != NULL){
        savedInputs.push_back(p.getEmail());
    }else{
        savedInputs.push_back("");
    }
    if(p.getDescription() != NULL){
        savedInputs.push_back(p.getDescription());
    }else{
        savedInputs.push_back("");
    }

    auto skills = resume->getSkills();

    QString s = "";
    for(int i = 0 ; i < skills.size(); i ++){
        Skill skill = skills.at(i);
        s.append(skill.getSkill());
        if(i != skills.size() -1)
            s.append(", ");
    }
    savedInputs.push_back(s);
    return savedInputs;
}
