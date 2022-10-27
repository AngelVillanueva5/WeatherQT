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
    weatherData.connectDB();
    double *ptr;
    ptr = weatherData.getAverage();
    ui->lblAvgTemp->setText(QString::number(ptr[0]));
    ui->lblAvgHum->setText(QString::number(ptr[1]));
    ui->lblAvgPres->setText(QString::number(ptr[2]));



    weatherData.setGraph();
    weatherData.getHistoric();
}
