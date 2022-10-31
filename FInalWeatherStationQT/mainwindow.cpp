#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weatherdata.h"
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDateTime tempDT = QDateTime::currentDateTime();
    currentDateTime = tempDT.toString("yyyy-MM-dd hh:mm:ss");
}

MainWindow::~MainWindow()
{
    delete ui;
    WeatherData weatherData;
}

void MainWindow::windowSetup(bool devToggle) {
    WeatherData weatherData;
    double *ptrAvg;
    int *ptrCur;
    ptrAvg = weatherData.getAverage(currentDateTime);
    ui->lblAvgTemp->setText(QString::number(ptrAvg[0]));
    ui->lblAvgHum->setText(QString::number(ptrAvg[1]));
    ui->lblAvgPres->setText(QString::number(ptrAvg[2]));

    ptrCur = weatherData.getRecentData(currentDateTime);
    ui->lblTemp->setText(QString::number(ptrCur[0]));
    ui->lblHum->setText(QString::number(ptrCur[1]));
    ui->lblAir->setText(QString::number(ptrCur[2]));

    // showns developer/test tools if radio button has been checked in login
    if(devToggle == true) {
        ui->frameDev->show();

    } else {
        ui->frameDev->hide();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    WeatherData weatherData;
    weatherData.setGraph(currentDateTime);
    weatherData.getHistoric(currentDateTime);
}


void MainWindow::on_pushButton_clicked()
{
    currentDateTime = ui->dateTimeDev->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    this->windowSetup(true);

}

