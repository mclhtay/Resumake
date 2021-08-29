#ifndef PDFOUTPUT_H
#define PDFOUTPUT_H

#include <memory>
#include <QString>
#include "../ResumeObject/resume.h"
#include "formatterfactory.h"
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QString>
#include <QWebView>
#include "Constants/guiconstants.h"
/*!
 * \brief Formats and outputs resume as PDF
 * \details This class contains methods for formatting and outputting the resume object to a pdf
 */
class PdfOutput
{
public:
    /*!
     * \brief PdfOutput Constructor
     * \param None
     * \returns None
     */
    PdfOutput();
    /*!
     * \brief Selects output dir
     * \details Allows the user to select a folder for the outputted pdf
     * \param None
     * \returns None
     */
    void selectOutputDir();
    /*!
     * \brief Set resume object
     * \details Sets the resume object to be used by the PdfOutput class
     * \param resume
     * \returns None
     */
    void setResume(Resume *resume);
    /*!
     * \brief Outputs pdf
     * \details Outputs the pdf using the chosen template
     * \param resume
     * \returns None
     */
    void outputPdf();

private:
    Resume *userResume;
    QString selectedOutputDir;
    FormatterFactory *factory;
    PdfFormatter *formatter;
};

#endif // PDFOUTPUT_H
