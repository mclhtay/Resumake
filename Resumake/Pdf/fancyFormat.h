#ifndef FANCYFORMATTER_H
#define FANCYFORMATTER_H

#include <QString>
#include "pdfformatter.h"

/*!
 * \brief Generates fancy format
 * \details Generates the fancy format for the resume in the form of a string containing the resume object data formatted with html
 */
class FancyFormatter : public PdfFormatter
{
public:
    /*!
     * \brief takes the resume object and returns formatted resume
     * \details formatResume takes the resume object as input and returns a string containing the resume object data formatted with html
     * \param resume - resume object
     * \return QString - html resume in fancy format
     */
    QString formatResume(Resume *resume);
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    FancyFormatter();
    /*!
     * \brief Destructor
     * \param none
     * \return none
     */
    ~FancyFormatter();
};

#endif // FANCYFORMATTER_H
