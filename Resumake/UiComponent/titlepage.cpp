#include "titlepage.h"
#include "../driver.h"

TitlePage::TitlePage(): UiComponent()
{
        createTitle();
        //createButtons();
}

void TitlePage:: render(QBoxLayout(* layout)){
    layout->addWidget(appTitle);
}

void TitlePage::createTitle(){
    appTitle = new QLabel;
    appTitle->setText("Resumake");
    appTitle->setFixedHeight(100);
    appTitle->setAlignment(Qt::AlignHCenter);
    appTitle->setStyleSheet("QLabel{font-size: 70px; font-weight: bold;}");

}
