#ifndef GUICONSTANTS_H
#define GUICONSTANTS_H

#include <QSize>

/*!
 * \brief Constant variables and getter functions for GUI
 * \details Holds enum for page components and GUI dimensions
 *   */
class GUIConstants
{
public:
    /*!
     * \brief Constructor
     * \param None
     * \returns None
     */
    GUIConstants();

    /*!
     * \brief Retrieves the GUI dimensions
     * \details Obtains fixed width and height and returns compatible dimension
     * \returns QSize - the dimensions of the GUI
     */
    QSize getDimensions();

    enum PAGE
    {
        PERSONALINFO,
        EDUANDEXP,
        ADDEXP,
        TEMPLATE,
    };

private:
    const int WIDTH = 660;
    const int HEIGHT = 850;
};

#endif // GUICONSTANTS_H
