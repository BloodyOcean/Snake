#include "point.h"

int Point::count = 0;

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getX()
{
    return this->x;
}

int Point::getY()
{
    return this->y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}



