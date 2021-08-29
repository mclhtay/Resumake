#ifndef ACCESSIBILITY_H
#define ACCESSIBILITY_H
#include <QApplication>
#include <QFile>

/*!
 * \brief Changes style sheet to fit accessibility requirements
 * \details Applying previously loaded stylesheets
 */
class Accessibility
{
public:
    /*!
     * \brief Contructor
     * \param None
     * \returns None
     */
    Accessibility();

    /*!
     * \brief Change to normal stylesheet
     * \details Loads the stylesheet responsible for normal display
     * \param q - pointer to QApplication to set stylesheet of
     * \returns None
     */
    void setNormal(QApplication *q);

    /*!
     * \brief Change to accessible stylesheet
     * \details Loads the stylesheet responsible for accessibility display
     * \param q - pointer to QApplication to set stylesheet of
     * \returns None
     */
    void setAccessible(QApplication *q);
};

#endif // ACCESSIBILITY_H
