#ifndef TITLEPAGE_H
#define TITLEPAGE_H
#include "uicomponent.h"

/*!
 * \brief Title Page
 * \details This is a sub class of the UI component class, it contains methods to render the title page
 */
class TitlePage : public UiComponent
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    TitlePage();
    /*!
     * \brief renders titlepage
     * \details A function for rendering the title page
     * \param layout - QBoxLayout containing the layout of the page
     * \return none
     */
    void render(QBoxLayout *layout) override;

private slots:
    /*!
     * \brief displays help
     * \details displays the help page in the UI
     * \param none
     * \return none
     */
    void help();

private:
    // title page elements and functions
    /*!
     * \brief displays title page
     * \details displays the title page in the UI
     * \param none
     * \return none
     */
    void createTitle();
    QLabel *appTitle;
};

#endif // TITLEPAGE_H
