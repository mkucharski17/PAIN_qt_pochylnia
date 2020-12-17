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

       group->clear();
       QPropertyAnimation *animation = new QPropertyAnimation(this,"pos");
       animation->setDuration(1000);

       animation->setStartValue(this->pos());
       int x = (index - currentIndex)*50;
       animation->setEndValue(QPointF(-x,0.3*x));
       group->addAnimation(animation);
       group->start();


//       animation->setStartValue(this->pos());
//       if(clickedIndex +1  >= currentIndex && clickedIndex -1 <= currentIndex )
//       {

//            int x = (index - currentIndex)*50 + (18-currentIndex -(clickedIndex-currentIndex))*50;
//           animation->setEndValue(QPointF(x,-0.3*x));
//           group->start();
//       }
//       else
//       {
//           int x;

//               x = (index - currentIndex)*50 - (2-currentIndex + (index-clickedIndex))*50;


//           animation->setEndValue(QPointF(-200,-200));
//           QPropertyAnimation *animation2 = new QPropertyAnimation(this,"pos");
//           animation2->setDuration(1000);
//           animation2->setStartValue(QPointF(-200,-200));
//           animation->setEndValue(QPointF(x,-0.3*x));


//           group->addAnimation(animation2);
//           group->start();
//       }

}

//void MyCircle::setIndex(int newIndex)
//{
//    qDebug() <<"previous" << index << " new "<< newIndex;
//  this->index = newIndex;
//}

int MyCircle::getIndex()
{
 return index;
}
QSequentialAnimationGroup* MyCircle::getAnimation()
{
 return group;
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


