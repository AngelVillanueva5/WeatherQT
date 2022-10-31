#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include <QString>
#include <QTime>


class WeatherData
{
public:
    WeatherData();
    double *getAverage(QString devdateTime);
    int *getHistoric(QString devdateTime);
    int *getRecentData(QString devdateTime);
    void windowSetup();
    void setGraph(QString devdateTime);
};
#endif // WEATHERDATA_H
