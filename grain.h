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

    int color =0;

    int new_color=0;

    GrainSettings* settings;
    QGraphicsScene* scene;
    QGraphicsRectItem* rect;


    int getAxleX(int id, int _table_x, int block_size);
    int getAxleY(int id, int _table_y, int block_size);
    int getX(int id, int _table_x);
    int getY(int id, int _table_y);
    void draw(QGraphicsScene* scene);
    void setColors();

    void setColor(int color_id);
    void updateColor();

    int randColor();
    Qt::GlobalColor getColor(int colorId);

    Grain(int _id, int _color, int _table_x, int _table_y, QGraphicsScene* scene);
    ~Grain();

private:

};

#endif // GRAIN_H
