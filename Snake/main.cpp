#include "mainwindow.h"

#include <QApplication>

#include "snake.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Snake snake;
    snake.show();
    return a.exec();
}
