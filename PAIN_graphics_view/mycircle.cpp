#include "mycircle.h"

MyCircle::MyCircle(double a, double b, double c, double d,char colorLetter, QGraphicsItem *parent): QGraphicsEllipseItem(a,b,c,d,parent)
{
   this->setBrush(getBrushFromLetter(colorLetter));

}

void MyCircle::select()
{
   this->setOpacity(0.3);
}

void MyCircle::unselect()
{
    this->setOpacity(1);
}

QBrush MyCircle::getBrushFromLetter(char letter)
{
    switch(letter){
    case 'R' : return QBrush(Qt::red);
    case 'G' : return QBrush(Qt::green);
    case 'B' : return QBrush(Qt::blue);
    }
}


