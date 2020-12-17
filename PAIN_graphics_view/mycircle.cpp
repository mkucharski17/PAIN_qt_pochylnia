#include "mycircle.h"

MyCircle::MyCircle(double a, double b, double c, double d,char colorLetter, QGraphicsItem *parent): QGraphicsEllipseItem(a,b,c,d,parent)
{
    index = a/50;
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

void MyCircle::move(int clickedIndex)
{
    qDebug() <<"clicked index" << clickedIndex;
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

       QPropertyAnimation *animation = new QPropertyAnimation(this,"pos");
       animation->setDuration(1000);
       group->addAnimation(animation);
       int x = (20 - clickedIndex-2)*50;
       animation->setStartValue(this->pos());
       if(index >=17)
       {
           animation->setEndValue(QPointF(x,-0.3*x));
           group->start();
       }
       else
       {
           animation->setEndValue(QPointF(-200,-200));
           QPropertyAnimation *animation2 = new QPropertyAnimation(this,"pos");
           animation2->setDuration(1000);
           animation2->setStartValue(QPointF(-200,-200));
           animation2->setEndValue(QPointF(-150,0.3*150));


           group->addAnimation(animation2);
           group->start();
       }

}

void MyCircle::setIndex(int newIndex)
{
    qDebug() <<"previous" << index << " new "<< newIndex;
  this->index = newIndex;
}

int MyCircle::getIndex()
{
 return index;
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
    qDebug() << index;
    emit ballClicked(index);
    QGraphicsItem::mousePressEvent(event);
}


