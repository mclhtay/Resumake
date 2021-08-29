#ifndef ENDINGPAGE_H
#define ENDINGPAGE_H

#include "uicomponent.h"

/*!
 * \brief Ending Page
 * \details This is a sub class of the UI component class, it contains methods to render the ending page
 */
class EndingPage : public UiComponent
{
    Q_OBJECT;

public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    EndingPage();
    /*!
     * \brief renders ending
     * \details A function for rendering ending page
     * \param layout - QBoxLayout containing the layout of the page
     * \return none
     */
    void render(QBoxLayout *layout) override;

private:
    QLabel *titleLabel;
};

#endif // ENDINGPAGE_H
