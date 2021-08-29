#include "mainwindow.h"
#include <QApplication>
#include "driver.h"

int main(int argc, char *argv[])
{
    QApplication resumake(argc, argv);
    // sets the default global styles for the application

    resumake.setStyleSheet(""
                           "QWidget{font-family: Arial, Helvetica, sans-serif; background-color: #152042; margin-left: 40px; margin-right: 40px;}"
                           "QPushButton{color:white; font-size: 16px; font-weight: bold; background-color: #299E8D; border-radius: 15px;padding:10px;min-width: 60px;}"
                           "QPushButton:focus {border: 3px solid white; outline: none; color: white;}"
                           "QLabel{color: white; font-size: 16px; font-weight: bold;}"
                           "QLineEdit{color: #BBC6EA; font-size: 14px; font-weight: bold; border: 0; border-bottom: 2px solid #299E8D; padding-top: 0px;}");

    // creates the driver class, which takes care of all transitions within the app
    Driver * driver = new Driver;
    driver->startApplication();

    return resumake.exec();

}
