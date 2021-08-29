#ifndef PERSONALINFOPAGE_H
#define PERSONALINFOPAGE_H
#include "uicomponent.h"
#include "horizontalinput.h"

/*!
 * \brief Personal Info Page
 * \details This is a sub class of the UI component class, it contains methods to render the personal information page as well as accept input from the user
 */
class PersonalInfoPage : public UiComponent
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    PersonalInfoPage();
    /*!
     * \brief renders personal info
     * \details A function for rendering personal info page
     * \param layout - QBoxLayout containing the layout of the page
     * \return none
     */
    void render(QBoxLayout *layout) override;
    /*!
     * \brief gets input
     * \details A function getting the user input
     * \param none
     * \return QVector containing strings of user input
     */
    QVector<QString> getInput() override;
    /*!
     * \brief sets input
     * \details A function setting the user input
     * \param inputs - QVector of strings entered by the user
     * \return none
     */
    void setInput(QVector<QString> inputs) override;

private:
    // template page elements and functions
    const int NUM_FIELDS = 5;
    HorizontalInput *fields[5];
    QLabel *pageLabel;
    const char *fieldDescriptions[5] = {"Full Name: ", "Email: ", "Phone: ", "Description: ", "Skills: "};
    const char *fieldPlaceholders[5] = {"Tala Buwadi", "tbuwadi@uwo.ca", "519-123-4567",
                                        "What're your career goals/objectives?", "Enter skills separated by commas"};
};

#endif // PERSONALINFOPAGE_H
