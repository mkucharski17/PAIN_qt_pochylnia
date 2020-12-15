#include "mycircle.h"

MyCircle::MyCircle(double a, double b, double c, double d,char colorLetter, QGraphicsItem *parent): QGraphicsEllipseItem(a,b,c,d,parent)
{
    index = a/50;
    this->setBrush(getBrushFromLetter(colorLetter));
    animation = new QPropertyAnimation(this,"pos");
    animation->setDuration(1000);

}

void MyCircle::select()
{
   this->setOpacity(0.3);
}

void MyCircle::unselect()
{
    this->setOpacity(1);     
}

void MyCircle::move()
{
   if(index >= clickedIndex -1)
   {
       if(this->opacity() == 0.3)
           animation->setEndValue(QPointF(200,200));
       else
           animation->setEndValue(QPointF(-200,-200));

       animation->start();
   }

}

void MyCircle::setClickedIndex(int index)
{
  clickedIndex = index;
}

QBrush MyCircle::getBrushFromLetter(char letter)
{
    switch(letter){
    case 'R' : return QBrush(Qt::red);
    case 'G' : return QBrush(Qt::green);
    case 'B' : return QBrush(Qt::blue);
    }
}


