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

    void exportToFile();
    void randomColor(QGraphicsScene* scene);
    int getIdByAxles(int ax, int ay, int block_size);
    void setColorById(int id, QGraphicsItem *item);



    Table(int size_x, int size_y, QGraphicsScene* scene);
    ~Table();

private:

};

#endif // TABLE_H
