#ifndef PLANTS_H
#define PLANTS_H
#include <QFile>
#include <QTextStream>>
#include <QString>

class plants
{
private:
    QString date_when_planted;
    QString name;
    QString water;
    QString handle;
    QString grows;

public:
    plants();
    plants(QString date_when_planted, QString name, QString water, QString handle, QString grows);
    QString get_name();
    QString get_date_when_planted();
    QString get_water();
    QString get_handle();
    QString get_grows();

    ~plants();
};
#endif // PLANTS_H
