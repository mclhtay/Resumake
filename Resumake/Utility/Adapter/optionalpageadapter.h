#ifndef OPTIONALPAGEADAPTER_H
#define OPTIONALPAGEADAPTER_H

#include "./pageadapter.h"

/*!
 * \brief Page adapter for Optional Page
 * \details Holds concrete implementations of required methods
 */
class OptionalPageAdapter : public PageAdapter
{
public:
    /*!
     * \brief Constructor
     * \param None
     * \returns None
     */
    OptionalPageAdapter();

    /*!
     * \brief Validates all user inputs on the Optional Page
     * \details Run through all corresponding error checkers on Optional Page  inputs
     * \param userInputs - string vector of all user inputs on current page
     * \returns QString - a string containing the errormessage if validation failed, empty otherwise
     */
    QString validateInput(QVector<QString> inputs) override;

    /*!
     * \brief Updates the resume to store Optional Page  inputs
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

private:
    /*!
     * \brief Creates an employment object
     * \details Creates an instance of employment object
     * \param position - string representing position
     * \param location - string representing location
     * \param date - string representing date
     * \param description - string representing description
     * \param type - string representing type, defaults to employment
     * \returns Employment - an object of Employment
     */
    Employment createExperience(QString position, QString location, QString date, QString description, QString type);
};

#endif // OPTIONALPAGEADAPTER_H
