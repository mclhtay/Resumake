#ifndef PERSONALINFO_H
#define PERSONALINFO_H
#include <QString>

/*!
 * \brief Stores personal information
 * \details This class stores personal information about the user and contains methods for storing and retrieving that information
 */
class PersonalInfo
{
public:
    /*!
     * \brief Constructor
     * \param none
     * \return none
     */
    PersonalInfo();

    /*!
     * \brief sets name
     * \details A function for setting name
     * \param s - QString containing name
     * \return none
     */
    void setName(QString s);
    /*!
     * \brief sets phone number
     * \details A function for setting phone number
     * \param s - QString containing phone number
     * \return none
     */
    void setPhoneNumber(QString s);
    /*!
     * \brief sets email
     * \details A function for setting email
     * \param s - QString containing email
     * \return none
     */
    void setEmail(QString s);
    /*!
     * \brief sets linked in
     * \details A function for setting linked in
     * \param s - QString containing linked in
     * \return none
     */
    void setLinkedIn(QString s);
    /*!
     * \brief sets github
     * \details A function for setting github
     * \param s - QString containing github
     * \return none
     */
    void setGithub(QString s);
    /*!
     * \brief sets website
     * \details A function for setting website
     * \param s - QString containing website
     * \return none
     */
    void setWebsite(QString s);
    /*!
     * \brief sets description
     * \details A function for setting description
     * \param s - QString containing description
     * \return none
     */
    void setDescription(QString s);
    /*!
     * \brief Resets personal information
     * \details A function for clearing all stored personal information
     * \param none
     * \return none
     */
    void reset();

    /*!
     * \brief gets name
     * \details A function for getting the name
     * \param none
     * \return QString containing name
     */
    QString getName();
    /*!
     * \brief gets phone number
     * \details A function for getting the phone number
     * \param none
     * \return QString containing phone number
     */
    QString getPhoneNumber();
    /*!
     * \brief gets email
     * \details A function for getting the email
     * \param none
     * \return QString containing email
     */
    QString getEmail();
    /*!
     * \brief gets linked in
     * \details A function for getting the linked in
     * \param none
     * \return QString containing linked in
     */
    QString getLinkedIn();
    /*!
     * \brief gets github
     * \details A function for getting the github
     * \param none
     * \return QString containing github
     */
    QString getGithub();
    /*!
     * \brief gets website
     * \details A function for getting the website
     * \param none
     * \return QString containing website
     */
    QString getWebsite();
    /*!
     * \brief gets description
     * \details A function for getting the description
     * \param none
     * \return QString containing description
     */
    QString getDescription();

private:
    QString name;
    QString phoneNumber;
    QString email;
    QString linkedIn;
    QString github;
    QString website;
    QString description;
};

#endif // PERSONALINFO_H
