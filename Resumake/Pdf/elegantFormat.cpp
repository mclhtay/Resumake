#include <QString>
#include <QWidget>
#include "elegantFormat.h"
#include <QFile>
#include <QApplication>
ElegantFormatter::ElegantFormatter()
{

}
ElegantFormatter::~ElegantFormatter(){

}

QString ElegantFormatter::formatResume(Resume * resume){

QString html ="";

html += "<head> "
        "<style> "
        "body{ "
        "   font-family: Roboto, sans-serif; "
        "   margin: 50px; "
        "   padding-top: 30px; "
        //"   border-top: 20px solid #a3cacc; "
        "} "
        ".rCenter{ "
        "   text-align: center; "
        "} "
        ".rLeft{ "
        "   text-align: left; "
        "} "
        "li{"
        "   font-size: 18px;"
        "}"
        "p{ "
        "   margin: 0;"
        "  font-family: Cambria, sans-serif; font-size: 18px; "
        "} "
        "h1{ "
        "   font-size: 70px; "
        "   margin: 0; "
        "   font-family: cambria; "
        "   color: #3A6567; "
        "} "
        "h2{ "
        "   border-bottom: 10px solid #fbedc9; "
        "   width: 70px;"
        "   padding-bottom: 10px;"
        "   margin-top: 50px; "
        "   font-size: 20px; "
        "   color: #3A6567;"
        "} "
        "hr{ "
        "   border:0;"
        "   margin:0; "
        "   width:100%; "
        "   height:10px; "
        "   background: #a3cacc; "
        "} "
        "#profile{"
        "color: #80A2A4"
        "}"
        "h4{"
        "   margin-bottom: 0px;"
        "}"
        "</style> "
        "</head>"
        "<div class='rCenter'>";

html+=  "   <h1>" + resume->getPersonalInfo().getName() + "</h1>"
        "</div> "
        "<div class='rCenter'>";

html+=  "   <h3 id='profile'>"+resume->getPersonalInfo().getPhoneNumber()+"  •  "+ resume->getPersonalInfo().getEmail()+"</h3>"
        "</div>"
        "<br><hr>"
        "<div class='rLeft'>";

html+=  "   <h2>PROFILE</h2><p>" +resume->getPersonalInfo().getDescription()+ "</p>"
        "</div>"
        "<div class='rleft'>";
html+=  "<h2>SKILLS</h2><p><ul>";

auto skills = resume->getSkills();
for(auto skill : skills){
    html+= "<li>"+skill.getSkill()+"</li>";
}

html+=  "</ul></p>";
html+=  "</div>"
        "<div class='rleft'>"
        "   <h2>EDUCATION</h2>";

html+=  "   <p><h4>"+resume->getEducation().getInstitutionName()+"</h4></p>"
        "   <p>"+resume->getEducation().getEnrollmentDate()+ "-" +resume->getEducation().getGraduationDate()+"</p>"
        "   <p>"+resume->getEducation().getDescription()+"</p>"
        "</div>"
        "<div class='rleft'>"
        "   <h2>EXPERIENCE</h2>";

auto experiences = resume->getExperiences();

for(int i = 0; i < 3; i ++){
    auto exp = experiences[i];
    if(exp.getLocation().length() != 0){
        html +=  "   <p><h4>"+exp.getPosition()+"</h4></p>"
                 "   <p>"+exp.getLocation()+"</p>"
                 "   <p>"+exp.getDate()+"</p>"
                 "   <p>"+exp.getDescription()+"</p><br>";

    }
}

html+= "</div> "
       "<html>";

return html;
}
