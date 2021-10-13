/*Клас Point - ігровий піксель (яблуко чи блок змії)*/
#ifndef POINT_H
#define POINT_H

#include <queue>

class Point
{
protected:
    int x;
    int y;
    static int count;

public:
    Point(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};

#endif // POINT_H
