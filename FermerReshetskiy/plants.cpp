#include "plants.h"
plants::plants()
{

}
plants::~plants()
{

}
plants::plants(QString date_when_planted, QString name, QString water, QString handle, QString grows)
{
    this->date_when_planted = date_when_planted;
    this->name = name;
    this->water = water;
    this->handle = handle;
    this->grows = grows;
}
QString plants::get_name()
{
    return this->name;
}
QString plants::get_date_when_planted()
{
    return date_when_planted;
}
QString plants::get_water()
{
    return water;
}
QString plants::get_handle()
{
    return handle;
}
QString plants::get_grows()
{
    return grows;
}
