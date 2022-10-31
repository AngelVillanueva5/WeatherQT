#include "weatherdata.h"
#include <QSqlQuery>
#include <QLineSeries>
#include <iostream>
#include <QChart>
#include <QChartView>
#include <QMainWindow>
#include <QValueAxis>
#include <QTime>

WeatherData::WeatherData()
{

}

// retrieves average values such as: temperature, humidity and airpressure depending on day
// Qstring currentDateTime: date time used in sql statements set to current time when starting application and can be changed with dev mode
double* WeatherData::getAverage(QString currentDateTime) {
    static double avg[3];
    QSqlQuery query("SELECT ROUND(avg(temperature), 1) AS avgTemp, ROUND(avg(humidity), 1) AS avgHum, ROUND(avg(airpressure), 1) AS  avgPres FROM weather WHERE DATE(dateAndTime) = DATE(?)");
    query.addBindValue(currentDateTime);
    query.exec();
    query.first();
    for(int i = 0; i < 3; i++) {
        avg[i] = query.value(i).toDouble();
    }
    return avg;
}

// retrieves most recent weather data from database
// Qstring currentDateTime: date time used in sql statements set to current time when starting application and can be changed with dev mode
int* WeatherData::getRecentData(QString currentDateTime) {
    static int curData[3];
    QSqlQuery query;
    query.prepare("SELECT temperature, humidity, airpressure FROM weather WHERE dateAndTime <= ? ORDER BY dateAndTime DESC LIMIT 1;");
    query.addBindValue(currentDateTime);
    query.exec();
    query.first();
    for(int i = 0; i < 3; i++) {
        curData[i] = query.value(i).toInt();
    }

    return curData;
}

//retrieves data from the database to insert into graph
// Qstring currentDateTime: date time used in sql statements set to current time when starting application and can be changed with dev mode
int* WeatherData::getHistoric(QString currentDateTime) {
    static int historicTemp[7];
    QSqlQuery query("SELECT temperature  FROM weather WHERE dateAndTime >= ? ORDER BY dateAndTime ASC LIMIT 8");
    query.addBindValue(currentDateTime);
    query.exec();
    query.first();
    for(int i = 0; i <= 7; i++) {
        historicTemp[i] = query.value(0).toDouble();
        query.next();
    }
    return historicTemp;
}

// sets up datagraph and inserts data
// Qstring currentDateTime: date time used in sql statements set to current time when starting application and can be changed with dev mode
void WeatherData::setGraph(QString currentDateTime) {
    QDateTime tempDT = QDateTime::currentDateTime();
    int *ptr;
    ptr = this->getHistoric(currentDateTime);
    QLineSeries *series = new QLineSeries();

    for(int i = 0; i <= 8; i++) {
        series->append(QTime::currentTime().hour() + 1 + i, ptr[i]);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Temperature chart");
    chart->createDefaultAxes();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // sets up x and y axis of chart
    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;
    axisX->setRange(QTime::currentTime().hour() + 1, QTime::currentTime().hour() + 9);
    axisX->setTickCount(9);
    axisX->setLabelFormat("%.2f");
    chartView->chart()->setAxisX(axisX, series);

    axisY->setRange(-20, 40);
    axisY->setTickCount(13);
    axisY->setLabelFormat("%.2f");
    chartView->chart()->setAxisY(axisY, series);

    // sets up window and inserts chart
    QMainWindow *window = new QMainWindow;
    window->setCentralWidget(chartView);
    window->resize(600, 500);
    window->show();
}
