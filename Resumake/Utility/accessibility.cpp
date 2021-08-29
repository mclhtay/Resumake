#include "accessibility.h"

Accessibility::Accessibility()
{

}
void Accessibility::setNormal(QApplication *q){
    QFile styleFile( ":/Styles/Styles/Resources/Styles/NormalStyle.qss");
    styleFile.open( QFile::ReadOnly );

    // Apply the loaded stylesheet
    QString style(styleFile.readAll());
    q->setStyleSheet(style);
}
void Accessibility::setAccessible(QApplication *q){
    QFile styleFile( ":/Styles/Styles/Resources/Styles/AccessibleStyle.qss");
    styleFile.open( QFile::ReadOnly );

    // Apply the loaded stylesheet
    QString style(styleFile.readAll());
    q->setStyleSheet(style);
}
