#ifndef RESUME_H
#define RESUME_H
#include <QString>
#include "personalinfo.h"
#include "experience.h"
#include "employment.h"
#include "otherexperience.h"
#include "education.h"
#include "skill.h"
#include "volunteer.h"
#include <QVector>

/*!
 * \brief Stores resume information
 * \details This class contains resume information and has methods for storing and retrieving that information
 */
class Resume
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    Resume();
    /*!
     * \brief Gets Education
     * \details A function for getting the education objects
     * \param none
     * \return Education object containing education experience
     */
    Education getEducation();
    /*!
     * \brief Gets Skills
     * \details A function for getting the list of Skill objects
     * \param none
     * \return QVector containing Skill objects
     */
    QVector<Skill> getSkills();
    /*!
     * \brief Gets Experiences
     * \details A function for getting the list of experience objects
     * \param none
     * \return QVector containing Employment objects
     */
    QVector<Employment> getExperiences();
    /*!
     * \brief Gets personal info
     * \details A function for getting the personal info
     * \param none
     * \return PersonalInfo containing personal info
     */
    PersonalInfo getPersonalInfo();

    /*!
     * \brief Updates personal info
     * \details A function for updating personal info and storing it in Vector
     * \param name - QString containing name
     * \param phone - QString containing phone
     * \param email - QString containing email
     * \param description - QString containing description
     * \param linkedIn - QString containing linkedIn
     * \param github - QString containing github
     * \param website - QString containing website
     * \return none
     */
    void updatePersonalInfo(QString name, QString phone, QString email, QString description, QString linkedIn, QString github, QString website);
    /*!
     * \brief Sets education
     * \details A function for setting education
     * \param name - QString containing name
     * \param description - QString containing description
     * \param date - QString containing date
     * \param gdate - QString containing gdate
     * \return none
     */
    void setEducation(QString name, QString description, QString date, QString gdate);
    /*!
     * \brief Sets experiences
     * \details A function for setting experiences
     * \param emp - QVector containing Employment objects
     * \return none
     */
    void setExperiences(QVector<Employment> emp);
    /*!
     * \brief Sets skills
     * \details A function for setting skills
     * \param QVector containing Skill objects
     * \return none
     */
    void setSkills(QVector<Skill>);
    /*!
     * \brief Resets resume data
     * \details A function for clearing all stored resume data
     * \param none
     * \return none
     */
    void reset();
    /*!
     * \brief Set formatter
     * \details Setter for formatter, takes formatter type as int
     * \param formatter type as int
     * \return none
     */
    void setFormatter(int);
    /*!
     * \brief Gets formatter
     * \details A function for getting the formatter type
     * \param none
     * \return int containing formatter type
     */
    int getFormatter();

private:
    Education education;
    PersonalInfo personalInfo;
    QVector<Skill> skills;
    QVector<Employment> experiences;
    int formatterId;
};

#endif // RESUME_H
