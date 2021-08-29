#include "horizontalinput.h"

HorizontalInput::HorizontalInput(QString labelText, QString placeholder=""): UiComponent()
{
    label = new QLabel;
    lineEdit = new QLineEdit;
    boxLayout = new QVBoxLayout;

    boxLayout->setMargin(0);
    boxLayout->setContentsMargins(0,0,0,0);
    boxLayout->setSpacing(0);
    label->setMaximumHeight(40);
    label->setContentsMargins(0,0,0,0);
    label->setText(labelText);
    label->setBuddy(lineEdit);

    lineEdit->setPlaceholderText(placeholder);
    lineEdit->setClearButtonEnabled(true);
    lineEdit->setContentsMargins(3,0,0,0);
    boxLayout->addWidget(label);
    boxLayout->addWidget(lineEdit);
}

void HorizontalInput::render(QBoxLayout *layout){
    if(layout == nullptr || boxLayout == nullptr){
        return;
    }

    layout->addLayout(boxLayout);
}

QString HorizontalInput::getUserInput(){
    return lineEdit->text();
}

void HorizontalInput::setUserInput(QString s){
    lineEdit->setText(s);
}
