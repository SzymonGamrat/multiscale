#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>
#include <table.h>
#include "graphicsscene.h"

void GraphicsScene::setTable(Table *_table){

    this->table = _table;
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        QGraphicsScene::mousePressEvent(event);
        if(event->button() == Qt::LeftButton) {
            QPointF position = event->scenePos();
            QGraphicsItem *item = itemAt(position, QTransform());// it is your clicked item, you can do everything what you want. for example send it somewhere
            this->table->setColorById(this->table->getIdByAxles(position.rx(), position.ry(), this->table->grains[0]->settings->h), item);

            //rect->setBrush(QBrush(Qt::yellow));


            if (this->table->inclusion_active){
                int block_size = this->table->grains[0]->settings->h;

                int size = this->table->inclusion_size;


                int ry = (int)position.ry();
                    if (!ry) ry++;
                    if (ry == 1500) ry--;
                int rx = (int)position.rx();
                    if (!rx) rx++;
                    if (rx == 1500) rx--;

                int new_ry = 0;
                int new_rx = 0;

                for (int i = size/2 * -1; i< size/2 + size%2; i++){
                    int temp_ry = ry + i*5;
                    new_ry = this->table->getPeriodicInclusionY(temp_ry);
                    position.setY(new_ry);
                    for (int j = size/2 * -1; j< size/2 + size%2; j++){
                      new_rx = this->table->getPeriodicInclusionX(rx + j*5);
                      position.setX(new_rx);

                      if(this->table->isInCircle(rx,ry,new_rx,new_ry,size)){
                          QGraphicsItem *item2 = itemAt(position, QTransform());
                          this->table->setInclusionColor(this->table->getIdByAxles(new_rx, new_ry, block_size), item2);
                      }

                    }
                }
            }
        }
    }

