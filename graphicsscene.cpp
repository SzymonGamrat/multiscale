#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>
#include <table.h>
#include "graphicsscene.h"

GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

void GraphicsScene::setTable(Table *_table){

    this->table = _table;
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        QGraphicsScene::mousePressEvent(event);
        if(event->button() == Qt::LeftButton) {
            QPointF position = event->scenePos();            



            if (this->table->inclusion_active){
                this->table->addInlusion(position);
            }
            else{
                QGraphicsItem *item = itemAt(position, QTransform());// it is your clicked item, you can do everything what you want. for example send it somewhere
                this->table->setColorById(this->table->getIdByAxles(position.rx(), position.ry(), this->table->grains[0]->settings->h), item);
            }
        }
    }

void GraphicsScene::getUpdate()
{
        update();
}
