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
    Q_OBJECT

public:
    explicit GraphicsScene(QObject *parent = 0);
    Table* table;
    void setTable(Table *_table);
    void getUpdate();
    virtual ~GraphicsScene() {};

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


};



#endif // GRAPHICSSCENE_H
