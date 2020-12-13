#include "ramp.h"

Ramp::Ramp():QGraphicsItem()
{

}

QRectF Ramp::boundingRect() const
{
    return QRectF(0,0,1000,300);
}


void Ramp::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon triangle;
    triangle << QPoint(0,300) << QPoint(1000,300) << QPoint(1000,0);
    painter->setBrush(Qt::gray);
    painter->drawPolygon(triangle);
}


