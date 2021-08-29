#ifndef OTHEREXPERIENCE_H
#define OTHEREXPERIENCE_H
#include "experience.h"

/*!
 * \brief Stores other experience information
 * \details This is a sub class of the Experience class which stores information about other experiences and contains methods for storing and retrieving that information
 */
class OtherExperience : public Experience
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    OtherExperience();
    /*!
     * \brief sets heading
     * \details A function for setting the heading
     * \param s - QString containing heading
     * \return none
     */
    void setHeading(QString s);
    QString getHeading();
    /*!
     * \brief determines if new section
     * \details A function for determining if there is a new section
     * \param none
     * \return true if there is a new section, false if there is not
     */
    bool isNewSection();
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
     * \details A function for setting the date
     * \param s - QString containing the date
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
     * \brief resets other experience
     * \details A function for clearing all stored other experience data
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

private:
    QString heading;
    bool newSection;
};

#endif // OTHEREXPERIENCE_H
