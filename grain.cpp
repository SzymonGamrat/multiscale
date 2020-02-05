//==========================================================================================================
#include <grain.h>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>
#include<vector>
#include <fstream>
#include <QGraphicsSceneMouseEvent>
#include <random>
#include <iterator>
#include "color.h"
#include "grainsettings.h"


int Grain::getAxleX(int id, int _table_x, int block_size) {
    int return_ax = 0;
    return_ax = (id % _table_x) * block_size;
    return return_ax;

}

int Grain::getAxleY(int id, int _table_y, int block_size) {
    int return_ay = 0;
    return_ay = ((id / _table_y) - 1) * block_size;
    return return_ay;

}


void Grain::draw(QGraphicsScene* scene) {

    this->rect = new QGraphicsRectItem();
    rect->setRect(this->settings->ax, this->settings->ay, this->settings->h, this->settings->w);

    rect->setBrush(Qt::black);
    scene->addItem(rect);
}

void Grain::setColors(){

    this->colors.push_back(new Color(0, Qt::black));
    this->colors.push_back(new Color(1, Qt::yellow));
    this->colors.push_back(new Color(2, Qt::red));
    this->colors.push_back(new Color(3, Qt::cyan));
    this->colors.push_back(new Color(4, Qt::magenta));
    this->colors.push_back(new Color(5, Qt::gray));
    this->colors.push_back(new Color(6, Qt::white));
    this->colors.push_back(new Color(7, Qt::darkMagenta));
    this->colors.push_back(new Color(8, Qt::darkGreen));


}
int Grain::randColor(){

        int randomColor = rand() % this->colors.size();
        return randomColor;

}
Qt::GlobalColor Grain::getColor(int colorId)
{
    for (int i = 0; i < this->colors.size(); i++)
    {
        if (this->colors[i]->id == colorId) {
            return this->colors[i]->brush;
        }
        else if (colorId > this->colors.size()) {
            return Qt::white;
        }


    }


}

Grain::Grain(int _id, int _color, int _table_x, int _table_y, QGraphicsScene* scene)
{
    this->setColors();
    this->id = _id;
    this->color = _color;
    int block_size = 5;
    this->settings = new GrainSettings(this->getAxleX(this->id, _table_x, block_size),this->getAxleY(this->id, _table_y, block_size), block_size, block_size);
    this->draw(scene);
}

Grain::~Grain()
{
}
//==========================================================================================================

