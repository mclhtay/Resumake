#include "educationandexperiencespage.h"

EducationAndExperiencesPage::EducationAndExperiencesPage()
{
    createWorkExperienceSection();
    createEducationExperienceSection();

}

void EducationAndExperiencesPage::render(QBoxLayout * layout) {
    layout->addLayout(experienceBoxes[0]);
    layout->addLayout(experienceBoxes[1]);
}

void EducationAndExperiencesPage::createWorkExperienceSection(){
    experienceBoxes[0] = new QVBoxLayout;
    employmentLabel = new QLabel;
    employmentLabel->setText("Experience");
    employmentLabel->setAlignment(Qt::AlignLeft);
    employmentLabel->setFixedHeight(40);
    employmentLabel->setStyleSheet("QLabel{font-weight: bold; font-size: 18px}");


    companyName = new HorizontalInput(workExperienceDescriptions[0], "Amoogle");
    jobTitle = new HorizontalInput(workExperienceDescriptions[1], "Software Developer Intern");
    jobDate = new HorizontalInput(workExperienceDescriptions[2], "May 2020 - August 2021");
    jobResponsibilities = new HorizontalInput(workExperienceDescriptions[3], "Developed the company website.");

    experienceBoxes[0]->addWidget(employmentLabel);
    companyName->render(experienceBoxes[0]);
    jobTitle->render(experienceBoxes[0]);
    jobDate->render(experienceBoxes[0]);
    jobResponsibilities->render(experienceBoxes[0]);
}

void EducationAndExperiencesPage::createEducationExperienceSection(){
    experienceBoxes[1] = new QVBoxLayout;
    educationLabel = new QLabel;
    educationLabel->setText("Education");
    educationLabel->setAlignment(Qt::AlignLeft);
    educationLabel->setFixedHeight(40);
    educationLabel->setStyleSheet("QLabel{font-weight: bold; font-size: 18px}");

    educationName = new HorizontalInput(educationExperienceDescriptions[0], "Western University");
    degree = new HorizontalInput(educationExperienceDescriptions[1], "BS Computer Science");
    educationDate = new HorizontalInput(educationExperienceDescriptions[2], "2018");
    educationGDate = new HorizontalInput(educationExperienceDescriptions[3], "2022");

    experienceBoxes[1]->addWidget(educationLabel);
    educationName->render(experienceBoxes[1]);
    degree->render(experienceBoxes[1]);
    educationDate->render(experienceBoxes[1]);
    educationGDate->render(experienceBoxes[1]);
}


QVector<QString> EducationAndExperiencesPage::getInput(){
    QVector<QString> userInputs;

    userInputs.push_back(companyName->getUserInput());
    userInputs.push_back(jobTitle->getUserInput());
    userInputs.push_back(jobDate->getUserInput());
    userInputs.push_back(jobResponsibilities->getUserInput());

    userInputs.push_back(educationName->getUserInput());
    userInputs.push_back(degree->getUserInput());
    userInputs.push_back(educationDate->getUserInput());
    userInputs.push_back(educationGDate->getUserInput());
    return userInputs;
}
void EducationAndExperiencesPage::setInput(QVector<QString> inputs){
    companyName->setUserInput(inputs[0]);
    jobTitle->setUserInput(inputs[1]);
    jobDate->setUserInput(inputs[2]);
    jobResponsibilities->setUserInput(inputs[3]);

    educationName->setUserInput(inputs[4]);
    degree->setUserInput(inputs[5]);
    educationDate->setUserInput(inputs[6]);
    educationGDate->setUserInput(inputs[7]);
}
