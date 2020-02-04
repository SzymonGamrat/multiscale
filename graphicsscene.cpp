#include "graphicsscene.h"

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    //qDebug() << "in";
    if (mouseEvent->button() == Qt::LeftButton)
    {
//        QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());// it is your clicked item, you can do everything what you want. for example send it somewhere
//        QGraphicsEllipseItem *ell = qgraphicsitem_cast<QGraphicsEllipseItem *>(item);
//        if(ell)
//        {
//            ell->setBrush(QBrush(Qt::black));
//        }
//        else
//            qDebug() << "not ell" << mouseEvent->scenePos();
//        }
    }

}
