#include "errorchecker.h"

ErrorChecker::ErrorChecker()
{

}

string ErrorChecker::stringify(QString s){
    return s.toUtf8().constData();
}

bool ErrorChecker::checkName(QString name) {
    bool valid;

    //checking match
    regex e("[a-zA-Z]*[\\s]{1}[a-zA-Z].*");
    valid = regex_match(stringify(name), e);
    if (name.length() < 1 && name.length() > 30) valid = false;
    return valid;
}

bool ErrorChecker::checkEmail(QString email) {
    bool valid;

    //checking match
    regex e("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    valid = regex_match(stringify(email), e);
    return valid;
}


bool ErrorChecker::checkPhone(QString phone) {
    bool valid;

    //checking match
    regex e("[(]*[[:d:]]{3}[)]*-*[[:space:]]*[[:d:]]{3}-*[[:space:]]*[[:d:]]{4}");
    valid = regex_match(stringify(phone), e);

    return valid;
}

//Only checks length right now
bool ErrorChecker::checkLength(QString s){
    bool valid;

    //checking length (1-49 characters)
    valid = s.length() > 0 && s.length() < 50;

    return valid;
}

bool ErrorChecker::checkLongString(QString s){
    return s.length() > 0 && s.length() < 250;
}

bool ErrorChecker::checkInstitution(QString institution) {
    bool valid;

    //checking length (1-49 characters)
    valid = institution.length() > 0 && institution.length() < 50;

    return valid;
}

bool ErrorChecker::checkDate(QString date) {
    return checkLength(date);
}

bool ErrorChecker::checkDescription(QString desc) {
    bool valid;

    //checking length (1-150 characters)
    valid = desc.length() > 0 && desc.length() <= 150;

    return valid;
}
