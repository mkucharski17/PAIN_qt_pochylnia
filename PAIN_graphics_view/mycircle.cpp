#include "mycircle.h"

MyCircle::MyCircle(double a, double b, double c, double d,char colorLetter, QGraphicsItem *parent): QGraphicsEllipseItem(a,b,c,d,parent)
{

   this->color = new Color(colorLetter);
   this->setBrush(QBrush(color->getColor()));
}

Color MyCircle::getColor()
{
    return color->getColor();
}


