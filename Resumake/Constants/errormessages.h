#ifndef ERRORMESSAGES_H
#define ERRORMESSAGES_H
#include <QString>

/*!
 * \brief Constant variables and function related to Error Messages
 * \details Holds constant error messages
*/
class ErrorMessages
{
public:
    /*!
     * \brief Constructor
     * \param None
     * \returns None
     */
    ErrorMessages();

    /*!
     * \brief Retrieves the correct error message
     * \details Retrieves the error message corresponding to the message number
     * \param messageNum - int representing the index to retrieve the error message from
     * \returns QString - the error message
     */
    QString getErrorMessage(int messageNum);

private:
    QString *errorMessages[9] = {
        new QString("Unable to proceed, enter a first and last name"),
        new QString("Unable to proceed, check email"),
        new QString("Unable to proceed, check phone"),
        new QString("Unable to proceed, check description"),
        new QString("Unable to proceed, check skills"),
        new QString("Unable to proceed, check company or institution name"),
        new QString("Unable to proceed, check job title and degree"),
        new QString("Unable to proceed, check date on employment and education"),
        new QString("Unable to proceed, check job description"),
    };
};

#endif // ERRORMESSAGES_H
