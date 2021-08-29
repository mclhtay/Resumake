#include <QString>
#include <QWidget>
#include "techFormat.h"
#include <QFile>
#include <QApplication>
TechFormatter::TechFormatter()
{

}
TechFormatter::~TechFormatter(){

}

QString TechFormatter::formatResume(Resume * resume){

QString html ="";

html += "<head> "
        "<style> "
        "body{ "
        "   font-family: Roboto, sans-serif; "
        "   margin: 50px; "
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
        "   margin: 10px 0px 10px 0;"
        "   font-size: 18px; "
        "} "
        "h1{ "
        "   font-size: 70px; "
        "   margin: 0; "
        "   color: #336699; "
        "} "
        "h2{ "
        "   padding-bottom: 20px;"
        "   width: 70px;"
        "   padding-top: 20px;"
        "   margin: 0px; "
        "   font-size: 20px; "
        "   color: #336699;"
        "} "
        "hr{ "
        "   border:0;"
        "   margin:0; "
        "   width:100%; "
        "   height:2px; "
        "   background: 336699; "
        "} "
        "#profile{"
        "color: #80A2A4"
        "}"
        "span{"
        "   background-color: #336699;"
        "   font-weight: bold;"
        "   color: white;"
        "   margin: 10px;"
        "   padding: 10px;"
        "   border-radius: 10px;"
        "}"
        "h3{"
        "   font-size: 15px;"
        "}"
        "#skills{"
        "   margin-bottom: 30px;"
        "}"
        "h4{"
        "   margin-bottom: 0px;"
        "   font-style: bold;"
        "   font-size: 18px;"
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
html+=  "<h2>SKILLS</h2><p><div id='skills'>";

auto skills = resume->getSkills();
for(auto skill : skills){
    html+= "<span>"+skill.getSkill()+"</span>";
}

html+=  "</p>";
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
                 "   <p style='font-style: italic;'>"+exp.getDate()+"</p>"
                 "   <p>"+exp.getDescription()+"</p><br>";

    }
}

html+= "</div> "
       "<html>";

return html;
}
