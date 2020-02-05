#ifndef GRAIN_H
#define GRAIN_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>
#include<vector>
#include <fstream>
#include <QGraphicsSceneMouseEvent>
#include <random>
#include <iterator>
#include <color.h>
#include <grainsettings.h>

class Grain
{
public:

    int id;
    std::vector<Color*> colors;

    int color;
    GrainSettings* settings;
    QGraphicsScene* scene;
    QGraphicsRectItem* rect;


    int getAxleX(int id, int _table_x, int block_size);
    int getAxleY(int id, int _table_y, int block_size);
    void draw(QGraphicsScene* scene);
    void setColors();
    int randColor();
    Qt::GlobalColor getColor(int colorId);

    Grain(int _id, int _color, int _table_x, int _table_y, QGraphicsScene* scene);
    ~Grain();

private:

};

#endif // GRAIN_H
