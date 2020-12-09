#include "mycircle.h"

MyCircle::MyCircle()
{
    Pressed = false;
    setFlag(ItemIsMovable);
}

QRectF MyCircle::boundingRect() const
{
    return QRectF(0,0,100,100);

}

void MyCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);
    if(Pressed){
        brush.setColor(Qt::red);
    }
    else{
        brush.setColor(Qt::green);
    }

    painter->fillRect(rec,brush);
    painter->drawEllipse(rec);
}

void MyCircle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MyCircle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
