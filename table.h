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

    void exportToFile();

    void randomColor(QGraphicsScene* scene);
    int getIdByAxles(int ax, int ay, int block_size);
    void setColorById(int id, QGraphicsItem *item);

    void vonNeumann();



    Table(int size_x, int size_y, QGraphicsScene* scene);
    Table(QGraphicsScene* scene);
    ~Table();

private:

};

#endif // TABLE_H
