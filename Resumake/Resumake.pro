QT       += core gui
QT       += printsupport
QT += webkitwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Constants/errormessages.cpp \
    Constants/guiconstants.cpp \
    Constants/pdfconstants.cpp \
    Pdf/elegantFormat.cpp \
    Pdf/formatterfactory.cpp \
    ResumeObject/education.cpp \
    ResumeObject/employment.cpp \
    ResumeObject/experience.cpp \
    ResumeObject/otherexperience.cpp \
    ResumeObject/personalinfo.cpp \
    ResumeObject/resume.cpp \
    ResumeObject/skill.cpp \
    ResumeObject/volunteer.cpp \
    UiComponent/educationandexperiencespage.cpp \
    UiComponent/endingpage.cpp \
    UiComponent/horizontalinput.cpp \
    UiComponent/optionalexperiencespage.cpp \
    UiComponent/personalinfopage.cpp \
    UiComponent/templatepage.cpp \
    UiComponent/titlepage.cpp \
    UiComponent/uicomponent.cpp \
    Utility/Adapter/educationandexperiencepageadapter.cpp \
    Utility/Adapter/optionalpageadapter.cpp \
    Utility/Adapter/pageadapter.cpp \
    Utility/Adapter/personalinfopageadapter.cpp \
    Utility/accessibility.cpp \
    Utility/resumeutilities.cpp \
    Utility/errorchecker.cpp \
    driver.cpp \
    gui.cpp \
    main.cpp \
    mainwindow.cpp \
    Pdf/pdfoutput.cpp \
    Pdf/defaultformat.cpp \
    SaveAndLoad/IO.cpp \
    Pdf/techFormat.cpp \
    Pdf/fancyFormat.cpp

HEADERS += \
    Constants/errormessages.h \
    Constants/guiconstants.h \
    Constants/pdfconstants.h \
    Pdf/elegantFormat.h \
    Pdf/formatterfactory.h \
    ResumeObject/education.h \
    ResumeObject/employment.h \
    ResumeObject/experience.h \
    ResumeObject/otherexperience.h \
    ResumeObject/personalinfo.h \
    ResumeObject/resume.h \
    ResumeObject/skill.h \
    ResumeObject/volunteer.h \
    UiComponent/educationandexperiencespage.h \
    UiComponent/endingpage.h \
    UiComponent/horizontalinput.h \
    UiComponent/optionalexperiencespage.h \
    UiComponent/personalinfopage.h \
    UiComponent/templatepage.h \
    UiComponent/titlepage.h \
    UiComponent/uicomponent.h \
    Utility/Adapter/educationandexperiencepageadapter.h \
    Utility/Adapter/optionalpageadapter.h \
    Utility/Adapter/pageadapter.h \
    Utility/Adapter/personalinfopageadapter.h \
    Utility/accessibility.h \
    Utility/resumeutilities.h \
    Utility/errorchecker.h \
    driver.h \
    gui.h \
    mainwindow.h \
    Pdf/pdfformatter.h \
    Pdf/pdfoutput.h \
    Pdf/defaultformat.h \
    SaveAndLoad/IO.h \
    Pdf/techFormat.h \
    Pdf/fancyFormat.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Styles/Resources/Styles/AccessibleStyle.qss \
    Styles/Resources/Styles/NormalStyle.qss

RESOURCES += \
    Resources.qrc

