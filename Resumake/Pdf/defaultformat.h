#ifndef DEFAULTFORMATTER_H
#define DEFAULTFORMATTER_H

#include <QString>
#include "pdfformatter.h"

/*!
 * \brief Generates default format
 * \details Generates the default format for the resume in the form of a string containing the resume object data formatted with html
 */
class DefaultFormatter : public PdfFormatter
{
public:
    /*!
     * \brief takes the resume object and returns formatted resume
     * \details formatResume takes the resume object as input and returns a string containing the resume object data formatted with html
     * \param resume - resume object
     * \return QString - html resume in default format
     */
    QString formatResume(Resume *resume);
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    DefaultFormatter();
    /*!
     * \brief Destructor
     * \param none
     * \return none
     */
    ~DefaultFormatter();
};

#endif // DEFAULTFORMATTER_H
