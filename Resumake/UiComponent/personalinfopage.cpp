#include "personalinfopage.h"
#include "driver.h"

PersonalInfoPage::PersonalInfoPage(): UiComponent()
{
    for(int i = 0; i < NUM_FIELDS; i ++){
        fields[i] = new HorizontalInput(fieldDescriptions[i], fieldPlaceholders[i]);
    }

    pageLabel = new QLabel;
    pageLabel->setText("Tell me about you!");
    pageLabel->setStyleSheet("QLabel{font-size: 26px; font-weight: bold;}");
    pageLabel->setAlignment(Qt::AlignLeft);
    pageLabel->setFixedHeight(100);

    QFont f=pageLabel->font();
    f.setBold(true);
    f.setPointSize(30);

    pageLabel->setFont(f);
}

void PersonalInfoPage::render(QBoxLayout * layout){
    layout->addWidget(pageLabel);
    for(HorizontalInput * hi : fields){
        hi->render(layout);
    }
}


QVector<QString> PersonalInfoPage::getInput(){
    QVector<QString> userInputs;
    for(HorizontalInput * hi : fields){
        userInputs.push_back(hi->getUserInput());
    }
    return userInputs;
}
void PersonalInfoPage::setInput(QVector<QString> inputs){
    for(int i = 0; i < NUM_FIELDS; i ++){
        fields[i]->setUserInput(inputs.at(i));
    }

}
