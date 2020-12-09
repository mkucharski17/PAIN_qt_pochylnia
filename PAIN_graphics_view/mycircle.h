#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include<QPainter>
#include<QGraphicsItem>
#include<QDebug>

class MyCircle : public QGraphicsItem
{
public:
    MyCircle();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    bool Pressed;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

};

#endif // MYCIRCLE_H
