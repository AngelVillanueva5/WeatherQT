#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QSqlQuery>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    hostName = "";
    databaseName = "";
    username = "";
    password = "";
    loginState = false;
    developerToggle = false;
}

login::~login()
{
    delete ui;
}

// connects to database
bool login::connectDB() {
    MainWindow *window = new MainWindow;
    qDebug() << hostName;
    qDebug() << databaseName;
    qDebug() << username;
    qDebug() << password;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(username);
    db.setPassword(password);
    bool ok = db.open();
    if(ok == false) {
        qDebug() << "Database connection failed";
        return false;
    } else {
        loginState = true;
        developerToggle = ui->radiobtnDev->isChecked();
        window->windowSetup(developerToggle);
        window->show();
        this->close();
        return true;
    }
}

void login::on_pushButton_clicked()
{
    hostName = ui->lineHostName->text();
    databaseName = ui->lineDatabaseName->text();
    username = ui->lineUsername->text();
    password = ui->linePassword->text();

    this->connectDB();
}

