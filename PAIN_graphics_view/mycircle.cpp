#include "mycircle.h"

MyCircle::MyCircle(float a, float b, float c, float d,Qt::GlobalColor color): QGraphicsEllipseItem(a,b,c,d)
{
    this->setBrush(QBrush(color));
    this->setPen(Qt::NoPen);
}


void MyCircle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}

void MyCircle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsItem::mouseReleaseEvent(event);
}
