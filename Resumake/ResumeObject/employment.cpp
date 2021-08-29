#include "employment.h"

Employment::Employment():Experience()
{

}

void Employment::setLocation(QString s){
    this->location = s;
}
void Employment::setPosition(QString s){
    this->position = s;
}
void Employment::setDate(QString s){
    this->date = s;

}
void Employment::setDescription(QString s){
    this->description = s;
}
void Employment::setType(QString s){
    this->type =s;
}

void Employment::reset(){
    setLocation("");
    setPosition("");
    setDate("");
    setDescription("");
    setType("");
}

QString Employment::getLocation(){
    return this->location;
}
QString Employment::getPosition(){
    return this->position;
}
QString Employment::getDate(){
    return this->date;
}
QString Employment::getDescription(){
    return this->description;
}
QString Employment::getType(){
    return this->type;
}
