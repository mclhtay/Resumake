#include <QString>
#include <QWidget>
#include "fancyFormat.h"
#include <QFile>
#include <QApplication>
FancyFormatter::FancyFormatter()
{

}
FancyFormatter::~FancyFormatter(){

}

QString FancyFormatter::formatResume(Resume * resume){

QString html ="";

html += "<head> "
        "<link rel='preconnect' href='https://fonts.gstatic.com'>"
        "<link href='https://fonts.googleapis.com/css2?family=Galada&display=swap' rel='stylesheet'>"
        "<link rel='preconnect' href='https://fonts.gstatic.com'>"
        "<link href='https://fonts.googleapis.com/css2?family=Work+Sans:wght@400;500&display=swap' rel='stylesheet'>"
        "<style> "
        "body{ "
        "   font-family: 'Work Sans', sans-serif; "
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
        "   margin: 0;"
        "   font-size: 18px; "
        "} "
        "h1{ "
        "   font-size: 55px; "
        "   margin: 0; "
        "   font-family: 'Galada', cursive; "
        "   color:  #135056; "
        "} "
        "h2{ "
        "   font-family: 'Galada', cursive;"
        "   margin-top: 35px; "
        "   margin-bottom: 0px;"
        "   font-size: 30px; "
        "   color: #135056;"
        "} "
        "hr{ "
        "   border:solid 0.5px #D4D4D4;"
        "   margin-top:-5px; "
        "} "
        "h3{"
        "   font-size: 18px;"
        "   margin: 0;"
        "   margin-bottom: -20px;"
        "   margin-left: 5px;"
        "   font-weight: normal;"
        "}"
        "h4{"
        "   font-size: 18px;"
        "   margin-bottom: 0px;"
        "}"
        "</style> "
        "</head>"
        "<div class='rLeft'>";

html+=  "   <h1>" + resume->getPersonalInfo().getName() + "</h1>"
        "</div> "
        "<div class='rLeft'>";

html+=  "   <h3>"+resume->getPersonalInfo().getPhoneNumber()+" <br> "+ resume->getPersonalInfo().getEmail()+"</h3>"
        "</div>"
        "<br>"
        "<div class='rLeft'>";

html+=  "   <h2>Profile</h2>";
html+=  "   <hr><p>" +resume->getPersonalInfo().getDescription()+ "</p>"
        "</div>"
        "<div class='rleft'>";
html+=  "<h2>Skills</h2>";
html+=  "<hr><p><ul>";

auto skills = resume->getSkills();
for(auto skill : skills){
    html+= "<li>"+skill.getSkill()+"</li>";
}

html+=  "</ul></p>";
html+=  "</div>"
        "<div class='rleft'>"
        "   <h2>Education</h2>";

html+=  "   <hr><p><h4>"+resume->getEducation().getInstitutionName()+"</h4></p>"
        "   <p>"+resume->getEducation().getEnrollmentDate()+ "-" +resume->getEducation().getGraduationDate()+"</p>"
        "   <p>"+resume->getEducation().getDescription()+"</p>"
        "</div>"
        "<div class='rleft'>"
        "   <h2>Experience</h2><hr>";

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
