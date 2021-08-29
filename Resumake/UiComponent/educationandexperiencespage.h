#ifndef EDUCATIONANDEXPERIENCESPAGE_H
#define EDUCATIONANDEXPERIENCESPAGE_H

#include "uicomponent.h"
#include "horizontalinput.h"

/*!
 * \brief Education and Experiences Page
 * \details This is a sub class of the UI component class, it contains methods to render the education and experiences page as well as accept input from the user
 */
class EducationAndExperiencesPage : public UiComponent
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    EducationAndExperiencesPage();
    /*!
     * \brief renders education and work experience
     * \details A function for rendering education and work experience page
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
    //education and experience specifics
    /*!
     * \brief creates work experience
     * \details A function for creating work experience section in the UI
     * \param none
     * \return none
     */
    void createWorkExperienceSection();
    /*!
     * \brief creates education experience
     * \details A function for creating education experience section in the UI
     * \param none
     * \return none
     */
    void createEducationExperienceSection();

    QVBoxLayout *experienceBoxes[2];
    QLabel *employmentLabel;
    QLabel *educationLabel;
    const char *workExperienceDescriptions[4] = {"Company/Organization: ", "Job Title: ", "Date: ", "Responsibilities: "};
    const char *educationExperienceDescriptions[4] = {"Institution: ", "Degree: ", "Enrollment date: ", "Graduation date: "};

    HorizontalInput *companyName;
    HorizontalInput *jobTitle;
    HorizontalInput *jobDate;
    HorizontalInput *jobResponsibilities;

    HorizontalInput *educationName;
    HorizontalInput *degree;
    HorizontalInput *educationDate;
    HorizontalInput *educationGDate;
};

#endif // EDUCATIONANDEXPERIENCESPAGE_H
