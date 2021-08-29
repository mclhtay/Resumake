#ifndef PDFCONSTANTS_H
#define PDFCONSTANTS_H

#include <QString>

/*!
 * \brief Constant variables and getter functions for PDF
 * \details Number of templates and related getter function
 */
class PDFConstants
{
public:
    /*!
     * \brief Constructor
     * \param None
     * \returns None
     */
    PDFConstants();

    const static int NUM_FORMATTER = 4;

    /*!
     * \brief Retrieves the name of the template
     * \details Returns the corresponding template theme's name
     * \param id - int representation of template index number
     * \returns QString - the name of the template
     */
    static QString getFormatterName(int id)
    {
        QString formatterName[4] = {"Basic Theme", "Professional Theme", "Tech Industry Theme", "Fancy Theme"};
        return formatterName[id];
    }
};

#endif // PDFCONSTANTS_H
