#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // GRAPHICSSCENE_H
