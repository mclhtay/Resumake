#include "resumeutilities.h"


ResumeUtilities::ResumeUtilities()
{

}


void ResumeUtilities::adapt(GUIConstants::PAGE page){
    switch(page){
        case GUIConstants::PAGE::PERSONALINFO:
            pageAdapter = new PersonalInfoPageAdapter;
            break;
        case GUIConstants::PAGE::EDUANDEXP:
            pageAdapter = new EducationAndExperiencePageAdapter;
            break;
        case GUIConstants::PAGE::ADDEXP:
            pageAdapter = new OptionalPageAdapter;
            break;
         default:
            pageAdapter = new PersonalInfoPageAdapter;
            break;
    }
}

QVector<QString> ResumeUtilities::getStoredInputs(GUIConstants::PAGE page, Resume * resume){
    adapt(page);
    return pageAdapter->getStoredInputs(resume);
}
void ResumeUtilities::updateResume(GUIConstants::PAGE page, Resume * resume, QVector<QString> userInputs){
    adapt(page);
    pageAdapter->updateResume(resume, userInputs);
}
QString ResumeUtilities::validateResume(QVector<QString> userInputs, GUIConstants::PAGE page){
    adapt(page);
    return pageAdapter->validateInput(userInputs);

}

void ResumeUtilities::showPreview(Resume * r){
    FormatterFactory factory;
    PdfFormatter * f = factory.getFormatter(r->getFormatter());
    GUIConstants * gc = new GUIConstants;

    QWebView * webView = new QWebView;
    QString html = f->formatResume(r);
    webView->setWindowTitle("Preview");
    webView->setFixedSize(gc->getDimensions());
    webView->setHtml(html);
    webView->setStyleSheet("background-color: white;");
    webView->setZoomFactor(0.65);
    webView->show();

}
