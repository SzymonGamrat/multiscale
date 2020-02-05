#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>
#include <table.h>

class GraphicsScene : public QGraphicsScene
{
public:
    Table* table;

    void setTable(Table *_table);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // GRAPHICSSCENE_H
