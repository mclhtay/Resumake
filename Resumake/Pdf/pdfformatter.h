#ifndef PDFFORMATTER_H
#define PDFFORMATTER_H

#include <QString>
#include "../ResumeObject/resume.h"
/*!
 * \brief The PdfFormatter base class
 * \details This is the base class for pdf formatter objects
 */
class PdfFormatter
{
public:
    /*!
     * \brief formatResume virtual function
     * \details This function is the virtual function for formatResume to be overridden by sub classes
     * \param resume - a resume object
     * \return - a Qstring holding resume data as formatted html
     */
    virtual QString formatResume(Resume *resume) = 0;
    /*!
     * \brief Destructor
     * \param none
     * \return none
     */
    virtual ~PdfFormatter() {}
};

#endif // PDFFORMATTER_H
