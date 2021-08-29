#include "optionalexperiencespage.h"

OptionalExperiencesPage::OptionalExperiencesPage() : UiComponent()
{
    createWorkExperiencesSection();
}

void OptionalExperiencesPage::createWorkExperiencesSection()
{

    for (int i = 0; i < NUM_FIELDS; i++)
    {
        fields[i] = new HorizontalInput(workExperienceDescriptions[i % 4], "");
    }

    label = new QLabel;
    label->setText("More Experiences (Optional)");
    label->setStyleSheet("QLabel{font-size: 26px; font-weight: bold;}");
    label->setAlignment(Qt::AlignLeft);
    label->setFixedHeight(100);

    QFont f = label->font();
    f.setBold(true);
    f.setPointSize(30);

    label->setFont(f);

    experienceBoxes[0] = new QVBoxLayout;
    QLabel *label2 = new QLabel;
    label2->setText("Optional Experience 1");
    label2->setStyleSheet("QLabel{font-weight: bold; font-size: 18px}");
    label2->setAlignment(Qt::AlignLeft);
    experienceBoxes[0]->addWidget(label2);
    for (int i = 0; i < 4; i++)
    {
        fields[i]->render(experienceBoxes[0]);
    }
    experienceBoxes[1] = new QVBoxLayout;
    QLabel *label3 = new QLabel;
    label3->setText("Optional Experience 2");
    label3->setStyleSheet("QLabel{font-weight: bold; font-size: 18px}");
    label3->setAlignment(Qt::AlignLeft);
    experienceBoxes[0]->addWidget(label3);

    for (int i = 4; i < 8; i++)
    {
        fields[i]->render(experienceBoxes[1]);
    }
}

void OptionalExperiencesPage::render(QBoxLayout *layout)
{

    layout->addWidget(label);
    layout->addLayout(experienceBoxes[0]);
    layout->addLayout(experienceBoxes[1]);
};

QVector<QString> OptionalExperiencesPage::getInput()
{
    QVector<QString> userInputs;
    for (HorizontalInput *hi : fields)
    {
        userInputs.push_back(hi->getUserInput());
    }

    return userInputs;
}
void OptionalExperiencesPage::setInput(QVector<QString> inputs)
{
    for (int i = 0; i < NUM_FIELDS; i++)
    {
        fields[i]->setUserInput(inputs[i]);
    }
}
