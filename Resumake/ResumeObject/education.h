#ifndef EDUCATION_H
#define EDUCATION_H
#include <QString>

/*!
 * \brief Stores education information
 * \details This class stores information about the users education and contains methods for storing and retrieving that information
 */
class Education
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    Education();
    /*!
     * \brief Set institutionName
     * \details Setter for institutionName, takes institution name as QString input
     * \param s - institution name as QString
     * \return none
     */
    void setInstitutionName(QString s);
    /*!
     * \brief Set enrollmentDate
     * \details Setter for enrollmentDate, takes enrollment date as QString input
     * \param s - enrollment date as QString
     * \return none
     */
    void setEnrollmentDate(QString s);
    /*!
     * \brief Set graduationDate
     * \details Setter for graduationDate, takes graduation date as QString input
     * \param s - graduation date as QString
     * \return none
     */
    void setGraduationDate(QString s);
    /*!
     * \brief Set description
     * \details Setter for description, takes description as QString input
     * \param s - description as QString
     * \return none
     */
    void setDescription(QString s);
    /*!
     * \brief reset education
     * \details sets all of the attributes to nothing
     * \param none
     * \return none
     */
    void reset();

    /*!
     * \brief Returns institution name
     * \details Returns the institution name that is stored in institutionName
     * \param none
     * \return QString - the name of the institution
     */
    QString getInstitutionName();
    /*!
     * \brief Returns enrollment date
     * \details Returns the enrollment date that is stored in enrollmentDate
     * \param none
     * \return QString - the date of enrollment
     */
    QString getEnrollmentDate();
    /*!
     * \brief Returns graduation date
     * \details Returns the graduation date that is stored in graduationDate
     * \param none
     * \return QString - date of graduation
     */
    QString getGraduationDate();
    /*!
     * \brief Returns description
     * \details Returns the description that is stored in description
     * \param none
     * \return QString - the descrition
     */
    QString getDescription();

private:
    QString institutionName;
    QString enrollmentDate;
    QString graduationDate;
    QString description;
};

#endif // EDUCATION_H
