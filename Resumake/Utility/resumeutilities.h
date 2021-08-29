#ifndef RESUMEUTILITIES_H
#define RESUMEUTILITIES_H
#include "ResumeObject/resume.h"
#include "Adapter/pageadapter.h"
#include "Adapter/educationandexperiencepageadapter.h"
#include "Adapter/optionalpageadapter.h"
#include "Adapter/personalinfopageadapter.h"
#include "Constants/guiconstants.h"
#include <QWebView>
#include "Pdf/formatterfactory.h"

/*!
 * \brief Useful functions that access and acts on the Resume object directly
 * \details Holds functions related to Resume operations such as updating its content
 */
class ResumeUtilities
{
public:
    /*!
     * \brief Constructor
     * \param None
     * \returns None
     */
    ResumeUtilities();

    /*!
     * \brief Obtains and returns the stored input from current session
     * \details Obtain the correct page adapter and then retrieves corresponding inputs
     * \param page - the enum string corresponding to the page the user was on
     * \param resume - pointer to Resume
     * \returns QVector<QString> - string vector of user inputs
     */
    QVector<QString> getStoredInputs(GUIConstants::PAGE page, Resume *resume);

    /*!
     * \brief Updates the information in Resume
     * \details Obtains the correct page adapter then update the information stored in the resume
     * \param page - the enum string corresponding to the page the user was on
     * \param resume - pointer to Resume
     * \param userInputs - vector of strings of user inputs
     * \returns None
     */
    void updateResume(GUIConstants::PAGE page, Resume *resume, QVector<QString> userInputs);

    /*!
     * \brief Validates all user inputs on the GUI
     * \details Obtains the correct page adapter then run through all corresponding input validators
     * \param userInputs - string vector of all user inputs on current page
     * \param page - the enum string corresponding to the page the user was on
     * \returns QString - a string containing the errormessage if validation failed, empty otherwise
     */
    QString validateResume(QVector<QString> userInputs, GUIConstants::PAGE page);

    /*!
     * \brief Displays a preview of user's final resume
     * \details Using webview and selected template, displays a preview of the user's resume in new window
     * \param r - pointer to Resume object
     * \returns None
     */
    void showPreview(Resume *r);

private:
    PageAdapter *pageAdapter;

    /*!
     * \brief Returns the correct adapter based on the page the user was on
     * \details Based on the enum string representing the GUI page, decide on the right page adapter
     * \param page - the enum string corresponding to the page the user was on
     * \returns None
     */
    void adapt(GUIConstants::PAGE page);
};

#endif // RESUMEUTILITIES_H
