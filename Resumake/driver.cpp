#include "driver.h"


Driver::Driver()
{
}

void Driver::startApplication(){
    // initiating all required objects and calls to show the GUI
    resume = new Resume;
    gui = new Gui;
    gui->initializeResume(resume, new ResumeUtilities, new IO);
    gui->show();
}


void Driver::convertToPDF(Resume * r){
    // receives the completed resume object and outputs the pdf to default directory
    resume = r;
    PdfOutput output;
    output.setResume(resume);
    output.outputPdf();
}
