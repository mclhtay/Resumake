#ifndef EXPERIENCE_H
#define EXPERIENCE_H
#include <QString>

/*!
 * \brief The Experience  base class
 * \details This is the base class for Experience sub classes and contains virtual methods for storing and retrieving that information to be overridden by sub classes
 */
class Experience
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    Experience();
    /*!
     * \brief Virtual setLocation
     * \details A virtual function for setting location, to be overwritten by subclasses
     * \param s - QString containing location
     * \return none
     */
    virtual void setLocation(QString s) = 0;
    /*!
     * \brief Virtual setPosition
     * \details A virtual function for setting position, to be overwritten by subclasses
     * \param s - QString containing position
     * \return none
     */
    virtual void setPosition(QString s) = 0;
    /*!
     * \brief Virtual setDate
     * \details A virtual function for setting date, to be overwritten by subclasses
     * \param s - QString containing date
     * \return none
     */
    virtual void setDate(QString s) = 0;
    /*!
     * \brief Virtual setDescription
     * \details A virtual function for setting description, to be overwritten by subclasses
     * \param s - QString containing description
     * \return none
     */
    virtual void setDescription(QString s) = 0;
    /*!
     * \brief Virtual setType
     * \details A virtual function for setting type, to be overwritten by subclasses
     * \param s - QString containing type
     * \return none
     */
    virtual void setType(QString s) = 0;
    /*!
     * \brief Virtual reset
     * \details A virtual function for clearing all stored experience data, to be overwritten by subclasses
     * \param none
     * \return none
     */
    virtual void reset() = 0;
    /*!
     * \brief Virtual getLocation
     * \details A virtual function for retrieving location data, to be overwritten by subclasses
     * \param none
     * \return Qstring - the location stored in location
     */
    virtual QString getLocation() = 0;
    /*!
     * \brief Virtual getPosition
     * \details A virtual function for retrieving position data, to be overwritten by subclasses
     * \param none
     * \return Qstring - the position stored in position
     */
    virtual QString getPosition() = 0;
    /*!
     * \brief Virtual getDate
     * \details A virtual function for retrieving the stored date, to be overwritten by subclasses
     * \param none
     * \return Qstring - the date stored in date
     */
    virtual QString getDate() = 0;
    /*!
     * \brief Virtual getDescription
     * \details A virtual function for retrieving the description, to be overwritten by subclasses
     * \param none
     * \return Qstring - the description stored in description
     */
    virtual QString getDescription() = 0;
    /*!
     * \brief Virtual getType
     * \details A virtual function for retrieving the type, to be overwritten by subclasses
     * \param none
     * \return Qstring - the type stored in type
     */
    virtual QString getType() = 0;

protected:
    QString location;
    QString position;
    QString date;
    QString description;
    QString type;
};

#endif // EXPERIENCE_H
