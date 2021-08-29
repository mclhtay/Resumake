#include "otherexperience.h"

OtherExperience::OtherExperience():Experience()
{

}
void OtherExperience::setHeading(QString s){
    OtherExperience::heading = s;
}
QString OtherExperience::getHeading(){
    return OtherExperience::heading;
}
bool OtherExperience::isNewSection(){
    return OtherExperience::newSection;
}

void OtherExperience::setLocation(QString s){
    this->location = s;
}
void OtherExperience::setPosition(QString s){
     this->position = s;
}
void OtherExperience::setDate(QString s){
    this->date = s;

}
void OtherExperience::setDescription(QString s){
     this->description = s;
}
void OtherExperience::setType(QString s){
     this->type = s;
}

void OtherExperience::reset(){
    setHeading("");
    setLocation("");
    setPosition("");
    setDate("");
    setDescription("");
}

QString OtherExperience::getLocation(){
    return  this->location;
}
QString OtherExperience::getPosition(){
    return  this->position;
}
QString OtherExperience::getDate(){
    return  this->date;
}
QString OtherExperience::getDescription(){
    return  this->description;
}
QString OtherExperience::getType(){
    return  this->type;
}
