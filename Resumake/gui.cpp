#include "gui.h"


// forward declaration to prevent circular dependencies
class Driver{
public:
    void convertToPDF(Resume * r);
};

Driver * driver;
Accessibility * accessible;

Gui::Gui(QWidget *parent) : QDialog(parent)
{
    // initialization of the main GUI
    gc = new GUIConstants;
    mainLayout = new QVBoxLayout;
    driver = new Driver;
    state = 0;
    setLayout(mainLayout);
    setFixedSize(gc->getDimensions());
    setWindowTitle(tr("Resumake"));
    renderDisplay();
}

void Gui::initializeResume(Resume *r, ResumeUtilities *rr, IO * io){
    resume = r;
    ru = rr;
    this->io = io;
}

void Gui::clearLayout(QLayout * layout)
{
    //recursive layout removal
    // removes all deeply nested widgets and layout
    if(!layout){
        return;
    }
    while(auto item = layout->takeAt(0)){
        delete item->widget();
        if(item->layout() != nullptr){
            clearLayout(item->layout());
        }
        delete item->layout();
    }

}

void Gui::restartGui(){
    state= 0;
    resume->reset();
    renderDisplay();
}

void Gui::renderDisplay(){
    //always clear the current layout to prevent component overlaps
   clearLayout(mainLayout);
   //decide what component to render next based on current user state
   if(state == 0){
       displayingComponent = new TitlePage;
       createTitlePageButtons();
       createMenuButtons();
   }else if(state == 1){
       displayingComponent = new PersonalInfoPage;
       createMenuButtons();
       mainLayout->addLayout(MenuLayout);
   }else if(state == 2){
       displayingComponent = new EducationAndExperiencesPage;
       createMenuButtons();
       mainLayout->addLayout(MenuLayout);
   }else if(state == 3){
        displayingComponent = new OptionalExperiencesPage;
        createMenuButtons();
        mainLayout->addLayout(MenuLayout);
   }else if(state ==4){
       displayingComponent = new TemplatePage;
       createMenuButtons();
       mainLayout->addLayout(MenuLayout);
   }else{
       ru->showPreview(resume);
       convertButton = new QPushButton("Convert to PDF", this);
       prevButton = new QPushButton("Back", this);
       restartButton = new QPushButton("Restart", this);

       connect(convertButton, &QPushButton::clicked, this, &Gui::convert);
       connect(restartButton, &QPushButton::clicked, this, &Gui::restartGui);
       connect(prevButton, &QPushButton::clicked, this, &Gui::updateGui);
       displayingComponent = new EndingPage;

       displayingComponent->render(mainLayout);
       mainLayout->addWidget(convertButton);
       mainLayout->addWidget(prevButton);
       mainLayout->addWidget(restartButton);
       createMenuButtons();
       mainLayout->addLayout(MenuLayout);
       return;
   }

   //renders the new displaying component
   // if not in title page, restore previously saved user input from current session
   if(state != 0)
        restoreInfo();
   displayingComponent->render(mainLayout);
   if(state == 0){
       mainLayout->addWidget(startButton);
       mainLayout->addWidget(loadButton);
       mainLayout->addWidget(helpButton);
       mainLayout->addLayout(MenuLayout);
   }else{
       createDirectionalButtons();
       mainLayout->addLayout(buttonLayout);
   }
}

void Gui::createTitlePageButtons(){
    startButton = new QPushButton("Start");
    loadButton = new QPushButton("Load");
    helpButton = new QPushButton("Help");
    connect(startButton, &QPushButton::clicked, this, &Gui::updateGui);
    connect(loadButton, &QPushButton::clicked, this, &Gui::loadSave);
    connect(helpButton, &QPushButton::clicked, this, &Gui::help);
}

void Gui::createMenuButtons(){
    MenuLayout = new QHBoxLayout;
    closeButton = new QPushButton("Quit", this);
    accessiblityButton = new QPushButton("Change Mode", this);

    connect(accessiblityButton, &QPushButton::clicked, this, &Gui::changeMode);

    connect(closeButton, &QPushButton::clicked, this, &Gui::confirmQuit);
    MenuLayout->addWidget(accessiblityButton);
    if(state > 0 && state <4){
        saveButton = new QPushButton("Save", this);
        connect(saveButton, &QPushButton::clicked, this, &Gui::saveResume);
        MenuLayout->addWidget(saveButton);
    }

    MenuLayout->addWidget(closeButton);
}

void Gui::createDirectionalButtons(){
    buttonLayout = new QHBoxLayout;
    nextButton = new QPushButton("Next", this);
    connect(nextButton, &QPushButton::clicked, this, &Gui::updateGui);

    prevButton = new QPushButton("Back", this);
    connect(prevButton, &QPushButton::clicked, this, &Gui::updateGui);
    buttonLayout->addWidget(prevButton);
    buttonLayout->addWidget(nextButton);
    createMenuButtons();
}

void Gui::errorMessage(QString message){
    QMessageBox errorBox;
    errorBox.setText(message);
    errorBox.exec();
}

void Gui::confirmQuit(){
    QMessageBox::StandardButton yesOrNoBox;
    yesOrNoBox = QMessageBox::question(this, "Resumake", "Are you sure you want to quit? Progress will not be saved!", QMessageBox::Yes| QMessageBox::No);

    if(yesOrNoBox == QMessageBox::Yes){
       Gui::close();
    }
}
void Gui::help(){
    QMessageBox helpBox;
    helpBox.setText("Resumake is a simple resume maker.");
    helpBox.exec();
}

void Gui::convert(){
    errorMessage("Converting your info to pdf!");
    driver->convertToPDF(resume);
    QString outputPath = QDir::currentPath() + "/"+ resume->getPersonalInfo().getName() + "-resume.pdf";
    errorMessage("Rusume saved to: " + outputPath);
}

int i = -1;
void Gui::changeMode(){
    if(i==-1){
        //accessibility mode first time
        i=0;
    }
    if(i==0){
        //accessibility mode
        i=1;
        accessible->setAccessible(qApp);
    }else if(i==1){
        //regular mode
        i=0;
        accessible->setNormal(qApp);
    }
}

GUIConstants::PAGE Gui::getPageConstant(int state){
    switch(state){
    case 1:
        return gc->PAGE::PERSONALINFO;
    case 2:
        return gc->PAGE::EDUANDEXP;
    case 3:
        return gc->PAGE::ADDEXP;
    case 4:
        return gc->PAGE::TEMPLATE;
    default:
        return gc->PAGE::PERSONALINFO;
    }
}

void Gui::saveResume(){
    auto userInputs = displayingComponent->getInput();
    ru->updateResume(getPageConstant(state), resume, userInputs);
    QString path = io->saveResume(resume, state);
    errorMessage("Inputs saved to: \n"+path);
}

void Gui::loadSave(){
    int savedState = io->loadResume(resume);

    if(savedState == -1){
        errorMessage("Cannot load save file, no saved file found");
    }else{
        state = savedState;
        errorMessage("Save file loaded successfully");
        renderDisplay();
    }
}

void Gui::updateGui(){

    // if sender is next button, always validate user inputs on the current page before allowing the user
    // to proceed

    if(sender() == startButton){
        state++;
        renderDisplay();
        return;
    }

    auto userInputs = displayingComponent->getInput();

    if(sender() == nextButton){
        if(state == 4){
            int f = displayingComponent->getInput(1);
            resume->setFormatter(f);
        }else{
            QString validationResult = ru->validateResume(userInputs, getPageConstant(state));
            if(validationResult.length() != 0){
                errorMessage(validationResult);
                return;
            }
            ru->updateResume(getPageConstant(state), resume, userInputs);
        }
    }
    // update state if checks pass and re-render
    state += sender() == nextButton? 1 : -1;
    renderDisplay();
}

void Gui::restoreInfo(){
    if(state == 4){
        displayingComponent->setInput(0);
    }else{
       displayingComponent->setInput(ru->getStoredInputs(getPageConstant(state), resume));
    }
}


