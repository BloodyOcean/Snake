#include "snake.h"
#include <iostream>


void Snake::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter qp(this);
    drawLines(&qp);
}

void Snake::keyPressEvent(QKeyEvent *event)
{

    int key = event->key();
    if (key == Qt::Key_W)
    {
        direction = DIRECTION_FORWARD;
    }
    else if (key == Qt::Key_S) {
        direction = DIRECTION_BACKWARD;

    }
    else if (key == Qt::Key_A) {
        direction = DIRECTION_LEFT;
    }
    else if (key == Qt::Key_D) {
        direction = DIRECTION_RIGHT;

    }


}

void Snake::drawLines(QPainter *qp)
{
    if(isInit)
    {
        /*draww apple*/
        qp->setBrush(QBrush(Qt::red, Qt::SolidPattern));
        qp->drawEllipse(apple->getX(), apple->getY(), pixelSize, pixelSize);

        /*draw snake*/
        qp->setBrush(QBrush(Qt::green, Qt::SolidPattern));
        for(int i = 0; i < (int)this->snake.size(); i++)
        {
             qp->drawEllipse(snake[i].getX(), snake[i].getY(), this->pixelSize, this->pixelSize);

        }
    }
}

void Snake::initGame()
{
    this->isInit = true;
    direction = DIRECTION_RIGHT;
    generateApple();
    timerID = startTimer(delay);
}

void Snake::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if(isInit)
    {
        if(isFaced())
        {
            generateApple();
        }
        move();
    }

    repaint();

}

void Snake::generateApple()
{
    delete apple;
    QRandomGenerator generator;
    int appleY = rand() % fieldHeight;
    int appleX = rand() % fieldWidth;
    apple = new Apple(appleX * pixelSize, appleY * pixelSize);
}

bool Snake::isFaced()
{
    if(snake[0].getX() == apple->getX() && snake[0].getY() == apple->getY())
    {
        score++;
        extend();
        return true;
    }
    else {
        return false;
    }
}

void Snake::move()
{
    /*replace every point with previous*/
    for(int i = snake.size(); i > 0; i--)
    {
        snake[i].setX(snake[i - 1].getX());
        snake[i].setY(snake[i - 1].getY());
    }

    switch (direction) {
    case DIRECTION_BACKWARD:{
        int old_size = snake[0].getY();
        snake[0].setY(old_size + pixelSize);
        break;
    }
    case DIRECTION_FORWARD:{
        int old_size = snake[0].getY();
        snake[0].setY(old_size - pixelSize);
        break;
    }
    case DIRECTION_LEFT:{
        int old_size = snake[0].getX();
        snake[0].setX(old_size - pixelSize);
        break;
    }
    case DIRECTION_RIGHT:{
        int old_size = snake[0].getX();
        snake[0].setX(old_size + pixelSize);
        break;
    }

    }
}

void Snake::extend()
{
    Point pnt(snake.back().getX(), snake.back().getY());
    snake.push_back(pnt);
}

Snake::Snake(QWidget *parent)
    : QWidget(parent)
{
    srand(time(NULL));
    Point tmp(fieldWidth / 2 * pixelSize, fieldHeight / 2 * pixelSize);
    snake.push_back(tmp);
    initGame();
}
