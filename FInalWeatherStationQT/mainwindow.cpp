#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "weatherdata.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    ptrAvg = weatherData.getAverage();
    ui->lblAvgTemp->setText(QString::number(ptrAvg[0]));
    ui->lblAvgHum->setText(QString::number(ptrAvg[1]));
    ui->lblAvgPres->setText(QString::number(ptrAvg[2]));

    ptrCur = weatherData.getRecentData();
    ui->lblTemp->setText(QString::number(ptrCur[0]));
    ui->lblHum->setText(QString::number(ptrCur[1]));
    ui->lblAir->setText(QString::number(ptrCur[2]));

    weatherData.setGraph();
    weatherData.getHistoric();
    if(devToggle == true) {
        ui->frameDev->show();

    } else {
        ui->frameDev->hide();
    }
}
