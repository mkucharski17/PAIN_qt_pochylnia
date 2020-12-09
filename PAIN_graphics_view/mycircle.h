#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include<QPainter>
#include<QGraphicsItem>
#include<QDebug>

class MyCircle : public QGraphicsEllipseItem
{
public:
    MyCircle(float a, float b, float c, float d,Qt::GlobalColor  color);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

};

#endif // MYCIRCLE_H
