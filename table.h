#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <grain.h>
#include <QGraphicsScene>

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>

class Table
{
public:

    int size_x, size_y;
    std::vector<Grain*> grains;

    int inclusion_active = 0;
    int inclusion_size = 0;
    /*int rx =0;
    int ry =0;
    int new_rx = 0;
    int new_ry = 0;*/
    void exportToFile();

    void randomColor(QGraphicsScene* scene);
    int getIdByAxles(int ax, int ay, int block_size);
    int getPeriodicX(int i);
    int getPeriodicY(int j);
    int getPeriodicInclusionX(int i);
    int getPeriodicInclusionY(int j);
    bool isInCircle(int rx, int ry, int new_rx, int new_ry,int inclusion_size);
    void setColorById(int id, QGraphicsItem *item);
    void setInclusionColor(int id, QGraphicsItem *item);


    void vonNeumann();



    Table(int size_x, int size_y, QGraphicsScene* scene);
    Table(QGraphicsScene* scene);
    ~Table();

private:

};

#endif // TABLE_H
