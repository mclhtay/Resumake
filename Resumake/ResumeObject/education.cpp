#include "education.h"

Education::Education()
{

}
void Education::setInstitutionName(QString s){
    Education::institutionName = s;
}
void Education:: setEnrollmentDate(QString s){
     Education::enrollmentDate = s;
}
void  Education::setGraduationDate(QString s){
     Education::graduationDate=s;
}
void  Education::setDescription(QString s){
     Education::description = s;
}

void Education::reset(){
    setDescription("");
    setInstitutionName("");
    setEnrollmentDate("");
    setGraduationDate("");
}

QString  Education::getInstitutionName(){
    return  Education::institutionName;
}
QString  Education::getEnrollmentDate(){
     return  Education::enrollmentDate;
}
QString  Education::getGraduationDate(){
     return  Education::graduationDate;
}
QString  Education::getDescription(){
    return  Education::description;
}
