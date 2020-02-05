#ifndef COLOR_H
#define COLOR_H
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>
#include<vector>
#include <fstream>
#include <QGraphicsSceneMouseEvent>

class Color
{
public:

    int id;
    Qt::GlobalColor brush;

    Color(int _id, Qt::GlobalColor _brush);
    ~Color();

private:

};

#endif // COLOR_H
