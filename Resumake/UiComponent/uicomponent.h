#ifndef UICOMPONENT_H
#define UICOMPONENT_H
#include <QVector>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

/*!
 * \brief UI Component parent class
 * \details This is the parent class of the UI components, it contains virtual methods to render the pages and recieve use input which are overridden by the child classes
 */
class UiComponent : public QObject
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    UiComponent();
    /*!
     * \brief parent UI component
     * \details virtual function for rendering UI components to be overidden
     * \param layout - QBoxLayout containing the layout of the page
     * \return none
     */
    virtual void render(QBoxLayout *layout);

    /*!
     * \brief gets input
     * \details A virtual function for getting the user input, overridden by child classes
     * \param none
     * \return QVector containing strings of user input
     */
    virtual QVector<QString> getInput();
    /*!
     * \brief gets input
     * \details A virtual function for getting the user input, overridden by child classes
     * \param none
     * \return int containing user input
     */
    virtual int getInput(int);

    virtual void setInput(QVector<QString> inputs);
    virtual void setInput(int id);
};

#endif // UICOMPONENT_H
