#include "uicomponent.h"


UiComponent::UiComponent(): QObject()
{

}
void UiComponent::render(QBoxLayout * layout){
    layout->addWidget(new QLabel("Resumake"));
}
QVector<QString> UiComponent::getInput(){
    QVector<QString> v;
    return v;
}
int UiComponent::getInput(int i){
    return i;
}
void UiComponent::setInput(QVector<QString> inputs){
    inputs.push_back(" ");
}

void UiComponent::setInput(int id){
    return;
}
