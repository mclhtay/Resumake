#include "volunteer.h"

Volunteer::Volunteer() : Experience()
{

}

void Volunteer::setLocation(QString s){
    this->location = s;
}
void Volunteer::setPosition(QString s){
   this->position = s;
}
void Volunteer::setDate(QString s){
    this->date = s;

}
void Volunteer::setDescription(QString s){
    this->description = s;
}
void Volunteer::setType(QString s){
    this->type = s;
}

void Volunteer::reset(){
    setLocation("");
    setPosition("");
    setDate("");
    setDescription("");
    setType("");
}

QString Volunteer::getLocation(){
    return this->location;
}
QString Volunteer::getPosition(){
    return this->position;
}
QString Volunteer::getDate(){
    return this->date;
}
QString Volunteer::getDescription(){
    return this->description;
}
QString Volunteer::getType(){
    return this->type;
}
