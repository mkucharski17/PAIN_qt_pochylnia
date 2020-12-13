#ifndef RAMP_H
#define RAMP_H

#include<QtCore>
#include<QtGui>

#include "mycircle.h"
class Ramp: public QGraphicsItem

{
public:
    Ramp();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RAMP_H
