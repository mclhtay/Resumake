#ifndef IO_H
#define IO_H
#include <QJsonObject>
#include <QJsonDocument>
#include "ResumeObject/resume.h"
#include <QDir>
#include <QFileInfo>

/*!
 * \brief Handles saving user session and loading user session
 * \details Holds the save and load functions
 */
class IO
{
public:
    /*!
     * \brief Constructor
     * \param None
     * \returns None
     */
    IO();

    /*!
     * \brief Saves user inputs as a json in default path
     * \details Run through parsers and converters to store inputs from the resume into a json
     * \param resume - pointer to the Resume object
     * \returns QString - the string of the path where the json is saved
     */
    QString saveResume(Resume *, int);

    /*!
     * \brief Updates the resume by loading saved inputs from previous sessions
     * \details Run through parsers and converters to load inputs into the resume
     * \param resume - pointer to the Resume object
     * \returns int - a valid state integer if save file found, -1 if no file found
     */
    int loadResume(Resume *);

private:
    const QString DEFAULT_LOAD_PATH = QDir::currentPath() + "/save.json";
    QJsonObject educationInfo;
    QJsonObject personalInfo;
    QJsonObject skillInfo;
    QJsonObject experienceInfo[3];
    QJsonObject resInfo;
    QJsonDocument resum;

    /*!
     * \brief Convert skills object into storable string
     * \details Run through parsers and converters to convert skills into string
     * \param skills - vector of skills object
     * \returns QString - the string representation of the skills objects
     */
    QString skillsToString(QVector<Skill> skills);

    /*!
     * \brief Convert string representation of skills into vector of skills
     * \details Run through parsers and converters to convert string into skills
     * \param s - string representation of skills
     * \returns QVector<Skill> - vector of skills
     */
    QVector<Skill> stringToSkills(QString s);

    /*!
     * \brief Creates an employment object
     * \details Creates an instance of employment object
     * \param position - string representing position
     * \param location - string representing location
     * \param date - string representing date
     * \param description - string representing description
     * \param type - string representing type, defaults to employment
     * \returns Employment - an object of Employment
     */
    Employment createExperience(QString position, QString location, QString date, QString description, QString type = "Employment");
};

#endif // IO_H
