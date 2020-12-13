#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include<QtCore>
#include<QtGui>
#include<QGraphicsItem>
#include"colors.h"

class MyCircle : public QGraphicsEllipseItem
{

public:
    MyCircle(double a, double b, double c, double d,char colorLetter, QGraphicsItem *parent);
    Color getColor();
private:
    Color *color;
};

#endif // MYCIRCLE_H
