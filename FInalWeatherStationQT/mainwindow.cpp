#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weatherdata.h"
#include <QString>
#include "weatherdata.h"
#include <QSqlQuery>
#include <string>
#include <QLineSeries>
#include <iostream>
#include <QChart>
#include <QChartView>
#include <QMainWindow>

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



void MainWindow::on_btnStart_clicked()
{
    WeatherData weatherData;
    double *ptrAvg;
    int *ptrCur;
    weatherData.connectDB();
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


}
