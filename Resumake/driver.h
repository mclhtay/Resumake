#ifndef DRIVER_H
#define DRIVER_H

#include "ResumeObject/resume.h"
#include "gui.h"
#include "Utility/resumeutilities.h"
#include "Pdf/pdfoutput.h"
#include "SaveAndLoad/IO.h"

/*!
 * \brief This class takes care of the transition between GUI and resume converter
 * \details The driver class holds the sole instance to the GUI of the application and starts the entire application.
 * \details On check of GUI termination, the driver calls to convert saved results to PDF
 *
 */
class Driver
{

public:
    /*!
     * \brief Constructor call
     * \param None
     * \returns None
     */
    Driver();
    /*!
     * \brief starts the GUI
     * \details The function creates an instance of Resume, GUI, ResumeUtilities, and IO, and starts the GUI.
     * \param None
     * \returns None
     */
    void startApplication();
    /*!
     * \brief connects to the component responsible for creating pdf
     * \param r - The resume object that is ready to be converted to pdf
     * \returns None
     */
    void convertToPDF(Resume *r);

private:
    Gui *gui;
    Resume *resume;
};

#endif // DRIVER_H
