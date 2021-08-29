#ifndef SKILL_H
#define SKILL_H
#include <QString>

/*!
 * \brief Stores skill information
 * \details This class stores information about the users skills and contains methods for storing and retrieving that information
 */
class Skill
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    Skill();
    /*!
     * \brief Set skill
     * \details Setter for skill, takes skill as QString input
     * \param s - skill as QString
     * \return none
     */
    void setSkill(QString s);
    /*!
     * \brief gets skill
     * \details A function for getting the skill
     * \param none
     * \return QString containing skill
     */
    QString getSkill();
    /*!
     * \brief resets skill
     * \details A function for clearing all stored skill data
     * \param none
     * \return none
     */
    void reset();

private:
    QString skill;
    QString description;
};

#endif // SKILL_H
