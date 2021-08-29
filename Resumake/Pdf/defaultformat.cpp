#include <QString>
#include <QWidget>
#include "defaultformat.h"
#include <QFile>
#include <QApplication>
DefaultFormatter::DefaultFormatter()
{

}
DefaultFormatter::~DefaultFormatter(){

}

QString DefaultFormatter::formatResume(Resume * resume){

QString html ="";

html += "<html>"
        "   <head><style>"
        "   body{"
        "       font-family: arial, sans-serif;"
        "       margin: 20px;"
        "   }"
        "   h1{"
        "       font-size: 60px;"
        "   }"
        "   div{"
        "   font-size: 22px;"
        "   }"
        "   li{"
        "   font-size: 22px;"
        "   }"
        "   h4{"
        "   color: #525252;"
        "   margin-bottom: 0px;"
        "   }"
        "   </style></head>"
        "   <body>";


html += "<div align=center><h1>"+resume->getPersonalInfo().getName()+"</h1></div>";
html += "<div align=center>"+resume->getPersonalInfo().getPhoneNumber()+"</div>";
html += "<div align=center>"+resume->getPersonalInfo().getEmail()+"</div>";

html += "<hr>";
html+= "<div align=left>Profile: "+resume->getPersonalInfo().getDescription()+"</div>";

html += "<hr>";
html+= "<h2>Skills</h2>";
html+= "<ul>";
auto skills = resume->getSkills();
for(auto skill : skills){
    html+= "<li>"+skill.getSkill()+"</li>";
}
html+="</ul>";

html += "<hr>";
html += "<h2>Education</h2>";
html += "<div align=left><h4>"+resume->getEducation().getInstitutionName()+"</h4></div>";
html += "<div align=left>"+resume->getEducation().getEnrollmentDate()+" - "+resume->getEducation().getGraduationDate()+"</div>";
html += "<div align=left>"+resume->getEducation().getDescription()+"</div><br>";


html += "<hr>";
html += "<h2>Work Experience</h2>";

auto experiences = resume->getExperiences();

for(int i = 0; i < 3; i ++){
    auto exp = experiences[i];
    if(exp.getLocation().length() != 0){
        html += "<div align=left><h4>"+exp.getLocation()+"</h4></div>";
        html += "<div align=left>"+exp.getPosition()+"</div>";
        html += "<div align=left>"+exp.getDate()+"</div>";
        html += "<div align=left>"+exp.getDescription()+"</div>";
        html += "<br>";
    }
}

html += "</body>"
        "</html>";

return html;
}
