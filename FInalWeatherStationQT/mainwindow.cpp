#include "mainwindow.h"
#include "ui_mainwindow.h"
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



void MainWindow::on_btnStart_clicked()
{
    WeatherData weatherData;
    weatherData.connectDB();
    ui->lblAvgTemp->setText(weatherData.getAverage());
}
