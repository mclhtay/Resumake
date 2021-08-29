#include "templatepage.h"

TemplatePage::TemplatePage():UiComponent()
{

    pageLayout = new QVBoxLayout;
    pageLabel = new QLabel;
    pageLabel->setText("Select a formatter to style your resume!");
    pageLabel->setStyleSheet("QLabel{font-size: 26px; font-weight: bold;}");
    pageLabel->setAlignment(Qt::AlignLeft);
    pageLabel->setFixedHeight(100);

    for(int i =0; i < PDFConstants::NUM_FORMATTER; i ++){
        formatters[i] = new QPushButton;
        formatters[i]->setText(PDFConstants::getFormatterName(i));
        connect(formatters[i], &QPushButton::clicked, this, &TemplatePage::setSelected);
    }
}
void TemplatePage::render(QBoxLayout * layout){
    pageLayout->addWidget(pageLabel);

    for(QPushButton * button : formatters){
        pageLayout->addWidget(button);
    }

    layout->addLayout(pageLayout);

}

void TemplatePage::setSelected(){

   // change the color of the button that is selected

    for(int i =0; i < PDFConstants::NUM_FORMATTER; i ++){
        if(sender() == formatters[i]){
            TemplatePage::selectedFormatter = i;
            break;
        }
    }
}

int TemplatePage::getInput(int i){
    return TemplatePage::selectedFormatter;
}



void TemplatePage::setInput(int id){
    TemplatePage::selectedFormatter = id;
}
