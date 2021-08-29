#ifndef TECHFORMATTER_H
#define TECHFORMATTER_H

#include <QString>
#include "pdfformatter.h"

/*!
 * \brief Generates tech format
 * \details Generates the tech format for the resume in the form of a string containing the resume object data formatted with html
 */
class TechFormatter : public PdfFormatter
{
public:
    /*!
     * \brief takes the resume object and returns formatted resume
     * \details formatResume takes the resume object as input and returns a string containing the resume object data formatted with html
     * \param resume - resume object
     * \return QString - html resume in tech format
     */
    QString formatResume(Resume *resume);
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    TechFormatter();
    /*!
     * \brief Destructor
     * \param none
     * \return none
     */
    ~TechFormatter();
};

#endif // TECHFORMATTER_H
