#ifndef TEMPLATEPAGE_H
#define TEMPLATEPAGE_H

#include "uicomponent.h"
#include "Constants/pdfconstants.h"
#include "Utility/resumeutilities.h"

/*!
 * \brief Template Page
 * \details This is a sub class of the UI component class, it contains methods to render the template selection page as well as accept input from the user
 */
class TemplatePage : public UiComponent
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    TemplatePage();
    /*!
     * \brief renders template select
     * \details A function for rendering template selection page
     * \param layout - QBoxLayout containing the layout of the page
     * \return none
     */
    void render(QBoxLayout *layout) override;
    /*!
     * \brief sets input
     * \details A function setting the user input
     * \param id - int entered by the user
     * \return none
     */
    void setInput(int id) override;
    /*!
     * \brief gets input
     * \details A function getting the user input
     * \param none
     * \return int containing template type
     */
    int getInput(int) override;
private slots:
    /*!
     * \brief sets selected template
     * \details sets the template selected by the user in the UI
     * \param none
     * \return none
     */
    void setSelected();

private:
    int selectedFormatter = 0;
    QVBoxLayout *pageLayout;
    QPushButton *formatters[PDFConstants::NUM_FORMATTER];
    QLabel *pageLabel;
};

#endif // TEMPLATEPAGE_H
