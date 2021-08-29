#ifndef GUI_H
#define GUI_H

#include <QVBoxLayout>
#include <QDialog>
#include <QDir>
#include "UiComponent/uicomponent.h"
#include "UiComponent/titlepage.h"
#include "UiComponent/personalinfopage.h"
#include "UiComponent/educationandexperiencespage.h"
#include "UiComponent/optionalexperiencespage.h"
#include "UiComponent/templatepage.h"
#include "UiComponent/endingpage.h"
#include <QVector>
#include "ResumeObject/resume.h"
#include "Utility/resumeutilities.h"
#include "Utility/accessibility.h"
#include "Constants/guiconstants.h"
#include "SaveAndLoad/IO.h"

/*!
 * \brief This class controls the application's GUI
 * \details GUI page displayed to the user is controlled by a states variable. The class is also responsible for rendering different user interfaces, components, and respective actions such as those responding to user clicks
 */

class Gui : public QDialog
{

public:
    /*!
     * \brief Default constructor
     * \details Overrides inheriting parent to be a component of QWidget
     * \param None
     * \returns None
     */
    Gui(QWidget *parent = 0);

    /*!
     * \brief Changes the current viewing component based on state
     * \details Decides which component should be rendered next based on user state.
     * \details Creates and renders components, pages, restores saved user info.
     * \param None
     * \returns None
     */
    void renderDisplay();

    /*!
     * \brief Initializes and stores required objects
     * \details Takes in required object instances and stores their global reference
     * \param r - pointer to the sole Resume object used throughout the application
     * \param rr - pointer to ResumeUtilities object
     * \param io - pointer to IO object
     * \returns None
     */
    void initializeResume(Resume *r, ResumeUtilities *rr, IO *io);
private slots:
    /*!
     * \brief Responds to QPushButton clicks
     * \details Connects to prev and next buttons.
     * \details Depending on which, the function manipulates state and calls respective functions in ResumeUtilities.
     * \param None
     * \returns None
     */
    void updateGui();

    /*!
     * \brief Popup box demanding user confirmation on quitting the application
     * \details Connects with the quit button
     * \details On confirm, the application warns that progress would not be saved and terminates
     * \details On cancel, the popup box disappears.
     * \param None
     * \returns None
     */
    void confirmQuit();

    /*!
     * \brief Changes user interface to accessibility mode
     * \details Connects with the change mode button
     * \details Switches the user interface between accessibility mode and normal mode
     * \details Connects with the
     * \param None
     * \returns None
     */
    void changeMode();

    /*!
     * \brief Displays instructions on how to use the application
     * \details Connects with the help button
     * \param None
     * \returns None
     */
    void help();

    /*!
     * \brief Starts the process of converting user inputs to a pdf file
     * \details Connects with the convert button
     * \details Displays popups with instructions and output directory after sending control back to driver
     * \param None
     * \returns None
     */
    void convert();

    /*!
     * \brief Loads saved user inputs from previous sessions
     * \details Connects with the load button.
     * \details Calls responsible function from IO
     * \details If no saved file found, display error message
     * \details If saved file found, load the save, and render to the correct page
     * \param None
     * \returns None
     */
    void loadSave();

    /*!
     * \brief Save the current resume editing progress
     * \details Connects with the save button.
     * \details Saves all inputs on display and in Resume to a default path
     * \param None
     * \returns None
     */
    void saveResume();

private:
    /*!
     * \brief Restore previously saved progress in current session
     * \details Dynamically restores info based on displaying component and utilizes ResumeUtilities
     * \param None
     * \returns None
     */
    void restoreInfo();

    /*!
     * \brief Removes all rendered components on display
     * \details Recursively removes all widgets and layouts that are rendered to the main layout
     * \param layout - the main layout
     * \returns None
     */
    void clearLayout(QLayout *layout);

    /*!
     * \brief Creates prev and next buttons
     * \details Creates prev and next buttons, connect them with the correct slots and renders to main layout
     * \param None
     * \returns None
     */
    void createDirectionalButtons();

    /*!
     * \brief Creates start, help, and load buttons
     * \details Creates start, help, and load buttons, connect them with the correct slots and renders to main layout
     * \param None
     * \returns None
     */
    void createTitlePageButtons();

    /*!
     * \brief Creates change mode, save and quit buttons
     * \details Creates change mode, save and quit buttons, connect them with the correct slots and renders to main layout
     * \param None
     * \returns None
     */
    void createMenuButtons();

    /*!
     * \brief Creates popup dialog displaying a message
     * \details Creates popup dialog displaying the input message, disappears on confirmation
     * \param message - the displaying message
     * \returns None
     */
    void errorMessage(QString message);

    /*!
     * \brief Resets GUI variables and renders title page
     * \details Connects with the restart button
     * \details Resets state back to 0 and re-renders display
     * \param None
     * \returns None
     */
    void restartGui();

    /*!
     * \brief Obtain the enum corresponding to the input
     * \details Switches on the input and returns the enum corresponding to the page.
     * \param int - representing the state the GUI is currently in
     * \returns GUIConstants::PAGE - enum string
     */
    GUIConstants::PAGE getPageConstant(int);

    int state;
    const int LAST_STATE = 5;
    QBoxLayout *mainLayout;
    UiComponent *displayingComponent;
    QHBoxLayout *buttonLayout;
    QHBoxLayout *MenuLayout;
    QPushButton *startButton;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QPushButton *helpButton;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *restartButton;
    QPushButton *closeButton;
    QPushButton *convertButton;
    QPushButton *accessiblityButton;
    Resume *resume;
    ResumeUtilities *ru;
    GUIConstants *gc;
    IO *io;
};

#endif // GUI_H
