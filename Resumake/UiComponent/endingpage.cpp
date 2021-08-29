#include "endingpage.h"

EndingPage::EndingPage(): UiComponent()
{

    titleLabel = new QLabel;
    titleLabel->setText("All done!");
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont f = titleLabel->font();
    f.setBold(true);
    f.setPointSize(40);
    titleLabel->setFont(f);
    titleLabel->setFixedHeight(100);
}

void EndingPage::render(QBoxLayout * layout){
     layout->addWidget(titleLabel);
}
