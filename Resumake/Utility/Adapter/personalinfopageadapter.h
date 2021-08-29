#ifndef PERSONALINFOPAGEADAPTER_H
#define PERSONALINFOPAGEADAPTER_H

#include "./pageadapter.h"

/*!
 * \brief Page adapter for Personal Info Page
 * \details Holds concrete implementations of required methods
 */
class PersonalInfoPageAdapter : public PageAdapter
{
public:
    /*!
     * \brief Constructor
     * \param None
     * \returns None
     */
    PersonalInfoPageAdapter();

    /*!
     * \brief Validates all user inputs on the Personal info page
     * \details Run through all corresponding error checkers on personal info page inputs
     * \param userInputs - string vector of all user inputs on current page
     * \returns QString - a string containing the errormessage if validation failed, empty otherwise
     */
    QString validateInput(QVector<QString> inputs) override;

    /*!
     * \brief Updates the resume to store personal info page inputs
     * \details Run through parsers and converters to store inputs into the resume
     * \param resume - pointer to the Resume object
     * \param userInputs - string vector of all user inputs on current page
     * \returns None
     */
    void updateResume(Resume *resume, QVector<QString> inputs) override;

    /*!
     * \brief Retrieves stored user inputs for the current page
     * \details Run through parsers and converters to retrieve inputs from the resume
     * \param resume - pointer to the Resume object
     * \returns string vector - QVector<QString> storing all previously saved user inputs
     */
    QVector<QString> getStoredInputs(Resume *resume) override;
};

#endif // PERSONALINFOPAGEADAPTER_H
