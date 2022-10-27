#include "weatherdata.h"
#include <QSqlQuery>
#include <string>
#include <QLineSeries>
#include <iostream>

WeatherData::WeatherData()
{

}

double* WeatherData::getAverage() {
    static double avg[3];
    QSqlQuery query("SELECT ROUND(avg(temperature), 1) AS avgTemp, ROUND(avg(humidity), 1) AS avgHum, ROUND(avg(airpressure), 1) AS  avgPres  FROM weather WHERE dateAndTime > '2022-10-23 00:00:00' AND dateAndTime < '2022-10-23 23:59:59'");
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
