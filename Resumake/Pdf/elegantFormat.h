#ifndef ELEGANTFORMATTER_H
#define ELEGANTFORMATTER_H

#include <QString>
#include "pdfformatter.h"

/*!
 * \brief Generates elegant format
 * \details Generates the elegant format for the resume in the form of a string containing the resume object data formatted with html
 */
class ElegantFormatter : public PdfFormatter
{
public:
    /*!
     * \brief takes the resume object and returns formatted resume
     * \details formatResume takes the resume object as input and returns a string containing the resume object data formatted with html
     * \param resume - resume object
     * \return QString - html resume in elegant format
     */
    QString formatResume(Resume *resume);
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    ElegantFormatter();
    /*!
     * \brief Destructor
     * \param none
     * \return none
     */
    ~ElegantFormatter();
};

#endif // ELEGANTFORMATTER_H
