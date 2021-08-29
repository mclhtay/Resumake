#include "pdfoutput.h"


PdfOutput::PdfOutput()
{
    factory = new FormatterFactory;
}



void PdfOutput::selectOutputDir(){
    //...todo,  right now it goes to whichever directory you run the program,  we can probably find some sort of file browser thing for it
}



void PdfOutput::setResume(Resume * resume){
    userResume = resume; 
}



void PdfOutput::outputPdf(){

formatter = factory->getFormatter(userResume->getFormatter());

QString outputPath = QDir::currentPath() + "/"+ userResume->getPersonalInfo().getName() + "-resume.pdf";

//I think the  PDFformatters should just return an html string for the resume (instead of doing it here, html = pdfformatter.formatResume()...)
QString html = formatter->formatResume(userResume);


QWebView document;
document.setHtml(html);
QPrinter printer(QPrinter::PrinterResolution);
printer.setOutputFormat(QPrinter::PdfFormat);
printer.setPaperSize(QPrinter::A4);
printer.setOutputFileName(outputPath);
printer.setPageMargins(QMarginsF(15, 15, 15, 15));

document.print(&printer);

 //DefaultFormatter formatter = new DefaultFormatter;
delete formatter;
}



