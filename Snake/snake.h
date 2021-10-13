#ifndef SNAKE_H
#define SNAKE_H

#include "point.h"
#include "apple.h"
#include <vector>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QWidget>
#include <QPainter>
#include <qrandom.h>

enum Directions
{
    DIRECTION_LEFT,
    DIRECTION_RIGHT,
    DIRECTION_FORWARD,
    DIRECTION_BACKWARD,
};

class Snake : public QWidget
{
protected:
    const static int pixelSize = 20;
    const static int fieldWidth = 20;
    const static int fieldHeight = 20;
    const static int delay = 150;

    int score = 0;
    bool isInit;
    int timerID;
    Point *apple = nullptr;

    std::vector<Point> snake;
    Directions direction = DIRECTION_RIGHT;

    void paintEvent(QPaintEvent *e) override;
    void keyPressEvent(QKeyEvent *event) override;
    void drawLines(QPainter *qp);
    void initGame();
    void timerEvent(QTimerEvent *e) override;
    void generateApple();
    bool isFaced();
    void move();
    void extend();


public:
    Snake(QWidget *parent = 0);
};

#endif // SNAKE_H
