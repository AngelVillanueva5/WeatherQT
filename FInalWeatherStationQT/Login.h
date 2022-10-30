#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool loginDatabase();
    bool connectDB();
      bool loginState;

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    QString hostName;
    QString databaseName;
    QString username;
    QString password;

    bool developerToggle;


};

#endif // LOGIN_H
