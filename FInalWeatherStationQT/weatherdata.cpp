#include "weatherdata.h"
#include <QSqlQuery>
#include <string>
#include <QLineSeries>
#include <iostream>
#include <QChart>
#include <QChartView>
#include <QMainWindow>

WeatherData::WeatherData()
{

}

double* WeatherData::getAverage() {
    static double avg[3];
    QSqlQuery query("SELECT ROUND(avg(temperature), 1) AS avgTemp, ROUND(avg(humidity), 1) AS avgHum, ROUND(avg(airpressure), 1) AS  avgPres  FROM weather WHERE dateAndTime > '2022-10-31 00:00:00' AND dateAndTime < '2022-10-31 23:59:59'");
    query.exec();
    query.first();
    for(int i = 0; i < 3; i++) {
        avg[i] = query.value(i).toDouble();
    }
    return avg;
}

void WeatherData::connectDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("databases.aii.avans.nl");
    db.setDatabaseName("sdvillan_db2");
    db.setUserName("sdvillan");
    db.setPassword("Ab12345");
    bool ok = db.open();
}

int* WeatherData::getHistoric() {
    static int historicTemp[7];
    QSqlQuery query("SELECT temperature  FROM weather WHERE dateAndTime > '2022-10-31 12:00:00' AND dateAndTime < '2022-10-31 20:00:01'");
    query.exec();
    query.first();
    for(int i = 0; i <= 7; i++) {
        historicTemp[i] = query.value(0).toDouble();
        query.next();
    }

    return historicTemp;
}

void WeatherData::setGraph() {
    int *ptr;
    ptr = this->getHistoric();
    QLineSeries *series = new QLineSeries();

    for(int i = 0; i <= 8; i++) {
         series->append(i, ptr[i]);
             qDebug() << historicTemp[i];
    }
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Simple line chart example");

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).back()->setRange(0, 8);
    chart->axes(Qt::Vertical).back()->setRange(-20, 40);
    chart->axes(Qt::Horizontal).back()->setTitleText("axis x [mm]");
    chart->axes(Qt::Vertical).back()->setTitleText("axis y [mm]");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *window = new QMainWindow;
    window->setCentralWidget(chartView);
    window->resize(400, 300);
    window->show();
}
