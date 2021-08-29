#ifndef ERRORCHECKER_H
#define ERRORCHECKER_H
#include <regex>
#include <QString>

using namespace std;

/*!
 * \brief Checks various inputs from the resume
 * \details Holds functions responsible for checking all user inputs from the resume
 *
class ErrorChecker
{
public:
    /*!
     * \brief Constructor
     * \param None
     * \returns None
     */
ErrorChecker();

/*!
     * \brief Checks user's name input
     * \details checks if the user's name is valid and contains first and last names
     * \param QString - the string representing user name
     * \returns bool - true if valid, false otherwise
     */
bool checkName(QString);

/*!
     * \brief Checks user's email input
     * \details checks if the user's email is valid
     * \param QString - the string representing user's email
     * \returns bool - true if valid, false otherwise
     */
bool checkEmail(QString);

/*!
     * \brief Checks user's phone input
     * \details checks if the user's phone is valid
     * \param QString - the string representing user's phone
     * \returns bool - true if valid, false otherwise
     */
bool checkPhone(QString);

/*!
     * \brief Checks user's education institute input
     * \details checks if the user's institute is valid
     * \param QString - the string representing user institute
     * \returns bool - true if valid, false otherwise
     */
bool checkInstitution(QString);

/*!
     * \brief Checks user's date input
     * \details checks if the date is valid
     * \param QString - the string representing date
     * \returns bool - true if valid, false otherwise
     */
bool checkDate(QString);

/*!
     * \brief Checks description field
     * \details checks if the description input is of correct length
     * \param QString - the string representing description
     * \returns bool - true if valid, false otherwise
     */
bool checkDescription(QString);

/*!
     * \brief Checks length of a string
     * \details checks if the string is of valid length; between 1 and 49 characters
     * \param QString - the string
     * \returns bool - true if valid, false otherwise
     */
bool checkLength(QString s);

/*!
     * \brief Checks length of a string
     * \details checks if the string is of valid length; between 1 and 150 characters
     * \param QString - the string
     * \returns bool - true if valid, false otherwise
     */
bool checkLongString(QString s);

private:
/*!
     * \brief Converts a QString to a std::string
     * \details Performs conversion between QString to std::string
     * \param QString - the string
     * \returns std::string
     */
string stringify(QString);
}
;

#endif //ERRORCHECKER_H
