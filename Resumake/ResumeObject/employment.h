#ifndef EMPLOYMENT_H
#define EMPLOYMENT_H
#include "experience.h"

/*!
 * \brief Stores employment information
 * \details This class stores information about the users employment and contains methods for storing and retrieving that information
 */
class Employment : public Experience
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    Employment();
    /*!
     * \brief sets location
     * \details A function for setting location
     * \param s - QString containing location
     * \return none
     */
    void setLocation(QString s) override;
    /*!
     * \brief sets position
     * \details A function for setting position
     * \param s - QString containing position
     * \return none
     */
    void setPosition(QString s) override;
    /*!
     * \brief sets date
     * \details A function for setting date
     * \param s - QString containing date
     * \return none
     */
    void setDate(QString s) override;
    /*!
     * \brief sets description
     * \details A function for setting description
     * \param s - QString containing description
     * \return none
     */
    void setDescription(QString s) override;
    /*!
     * \brief sets type
     * \details A function for setting type
     * \param s - QString containing type
     * \return none
     */
    void setType(QString s) override;
    /*!
     * \brief resets employment experience
     * \details A function for clearing all stored employment experience data
     * \param none
     * \return none
     */
    void reset() override;
    /*!
     * \brief gets location
     * \details A function for getting the location
     * \param none
     * \return QString containing location
     */
    QString getLocation() override;
    /*!
     * \brief gets position
     * \details A function for getting the position
     * \param none
     * \return QString containing position
     */
    QString getPosition() override;
    /*!
     * \brief gets date
     * \details A function for getting the date
     * \param none
     * \return QString containing date
     */
    QString getDate() override;
    /*!
     * \brief gets description
     * \details A function for getting the description
     * \param none
     * \return QString containing description
     */
    QString getDescription() override;
    /*!
     * \brief gets type
     * \details A function for getting the type
     * \param none
     * \return QString containing type
     */
    QString getType() override;
};

#endif // EMPLOYMENT_H
