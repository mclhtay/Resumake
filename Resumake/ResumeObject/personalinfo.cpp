#include "personalinfo.h"

PersonalInfo::PersonalInfo()
{

}

void PersonalInfo::setName(QString s){
    PersonalInfo::name = s;
}
void PersonalInfo::setPhoneNumber(QString s){
    PersonalInfo::phoneNumber = s;
}
void PersonalInfo::setEmail(QString s){
    PersonalInfo::email = s;
}
void PersonalInfo::setLinkedIn(QString s){
    PersonalInfo::linkedIn = s;
}
void PersonalInfo::setGithub(QString s){
    PersonalInfo::github = s;
}
void PersonalInfo::setWebsite(QString s){
    PersonalInfo::website = s;
}

void PersonalInfo::setDescription(QString s){
    PersonalInfo::description = s;
}
void PersonalInfo::reset(){
    setName("");
    setPhoneNumber("");
    setEmail("");
    setLinkedIn("");
    setGithub("");
    setWebsite("");
    setDescription("");
}

QString PersonalInfo::getName(){
    return PersonalInfo::name;
}
QString PersonalInfo::getPhoneNumber(){
    return PersonalInfo::phoneNumber;
}
QString PersonalInfo::getEmail(){
    return PersonalInfo::email;
}
QString PersonalInfo::getLinkedIn(){
    return PersonalInfo::linkedIn;
}
QString PersonalInfo:: getGithub(){
    return PersonalInfo::github;
}
QString PersonalInfo::getWebsite(){
    return PersonalInfo::website;
}

QString PersonalInfo::getDescription(){
    return PersonalInfo::description;
}
