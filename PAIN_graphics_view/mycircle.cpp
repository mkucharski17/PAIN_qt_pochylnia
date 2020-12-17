#include "mycircle.h"

MyCircle::MyCircle(double a, double b, double c, double d,char colorLetter, QGraphicsItem *parent): QGraphicsEllipseItem(a,b,c,d,parent)
{
    index = a/50;
    currentIndex = index;
    this->setBrush(getBrushFromLetter(colorLetter));
    this->setFlag(QGraphicsItem::ItemIsSelectable , true);
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
       animation->setDuration(1000);
       animation->setStartValue(this->pos());
       int x = (index - currentIndex)*50;
       animation->setEndValue(QPointF(-x,0.3*x));
       animation->start();
}

int MyCircle::getIndex()
{
 return index;
}
QPropertyAnimation* MyCircle::getAnimation()
{
 return animation;
}
void MyCircle::setCurrentIndex(int newIndex)
{
    qDebug() <<"previous" << index << " new "<< newIndex;
  this->currentIndex = newIndex;
}

int MyCircle::getCurrentIndex()
{
 return currentIndex;
}


QBrush MyCircle::getBrushFromLetter(char letter)
{
    switch(letter){
    case 'R' : return QBrush(Qt::red);
    case 'G' : return QBrush(Qt::green);
    case 'B' : return QBrush(Qt::blue);
    }
}

void MyCircle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() <<currentIndex;
    emit ballClicked(currentIndex);
    QGraphicsItem::mousePressEvent(event);
}


