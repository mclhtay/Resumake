#ifndef FORMATTERFACTORY_H
#define FORMATTERFACTORY_H

#include "Constants/pdfconstants.h"
#include "defaultformat.h"
#include "elegantFormat.h"
#include "techFormat.h"
#include "fancyFormat.h"
#include "pdfformatter.h"

/*!
 * \brief Factory for formatter class
 * \details Contains method to generate instances if formatter class depending on the selected format
 */
class FormatterFactory
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    FormatterFactory();
    /*!
     * \brief Returns formatter object
     * \param id The selected resume format
     * \details This class returns an instance of formatter sub class for the selected resume format
     * \return Instance of formatter sub class for the selected resume format
     */
    PdfFormatter *getFormatter(int id);
};

#endif // FORMATTERFACTORY_H
