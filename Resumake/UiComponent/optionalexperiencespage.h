#ifndef OPTIONALEXPERIENCESPAGE_H
#define OPTIONALEXPERIENCESPAGE_H

#include "uicomponent.h"
#include "horizontalinput.h"

/*!
 * \brief Optional Experiences Page
 * \details This is a sub class of the UI component class, it contains methods to render the optional experiences page as well as accept input from the user
 */
class OptionalExperiencesPage : public UiComponent
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    OptionalExperiencesPage();
    /*!
     * \brief renders optional experience
     * \details A function for rendering optional experience page
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
    /*!
     * \brief creates work experience
     * \details creates the work experience section in the UI
     * \param none
     * \return none
     */
    void createWorkExperiencesSection();

    QVBoxLayout *experienceBoxes[2];
    QLabel *label;
    const char *workExperienceDescriptions[4] = {"Company/Organization: ", "Job Title: ", "Date: ", "Responsibilities: "};

    HorizontalInput *fields[8];
    const int NUM_FIELDS = 8;
};

#endif // OPTIONALEXPERIENCESPAGE_H
