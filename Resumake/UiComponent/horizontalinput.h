#ifndef HORIZONTALINPUT_H
#define HORIZONTALINPUT_H
#include "uicomponent.h"

/*!
 * \brief Horizontal input
 * \details This is a sub class of the UI component class, it contains methods to render horizontal input as well as accept input from the user
 */
class HorizontalInput : public UiComponent
{
public:
    /*!
     * \brief Constructor
     * \param labelText - Qstring containing the label text
     * \param placeholder - Qstring containing the placeholder text
     * \return none
     */
    HorizontalInput(QString labelText, QString placeholder);
    /*!
     * \brief renders horizontal input
     * \details A function for rendering horizontal input
     * \param layout - QBoxLayout containing the layout of the page
     * \return none
     */
    void render(QBoxLayout *layout) override;
    /*!
     * \brief gets input
     * \details A function getting the user input
     * \param none
     * \return QString containing strings of user input
     */
    QString getUserInput();
    /*!
     * \brief sets input
     * \details A function setting the user input
     * \param s - QString entered by the user
     * \return none
     */
    void setUserInput(QString s);

private:
    QVBoxLayout *boxLayout;
    QLabel *label;
    QLineEdit *lineEdit;
};

#endif // HORIZONTALINPUT_H
