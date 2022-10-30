#ifndef LOGINDATABASE_H
#define LOGINDATABASE_H
#include <QString>

class loginDatabase
{
public:
    loginDatabase();
    bool login();
private:
    QString hostName;
    QString databaseName;
    QString username;
    QString password;
    bool developerToggle;
};

#endif // LOGINDATABASE_H
