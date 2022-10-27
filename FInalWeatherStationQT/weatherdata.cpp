#include "weatherdata.h"
#include <QSqlQuery>
#include <string>
#include <QLineSeries>

WeatherData::WeatherData()
{

}

QString WeatherData::getAverage() {
    QSqlQuery query("SELECT avg(temperature) FROM weather WHERE dateAndTime BETWEEN '2022-10-23 01:00:00' AND '2022-10-23 23:00:00'");
    query.exec();
    query.first();
    QString avg = query.value(0).toString();
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
