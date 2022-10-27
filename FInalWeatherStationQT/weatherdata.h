#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include <QString>


class WeatherData
{
public:
    WeatherData();
    double *getAverage();
    int getHistoric();
    int getData();
    void connectDB();
    void setGraph();
};
#endif // WEATHERDATA_H
