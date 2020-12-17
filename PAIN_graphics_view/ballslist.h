#ifndef BALLSLIST_H
#define BALLSLIST_H

#include"mycircle.h"
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QList>




class BallsList:public QObject
{
     Q_OBJECT
public:
    BallsList( QGraphicsItem *parent);
    MyCircle getBallAt(int);
    MyCircle getclickedBallIndex();
    QList<MyCircle*> getBalls();
public slots:
    void ballSelected(int index);
    void ballsAfterMoving();
    void ballsMoving();

signals:
    moveIsNotPossible();
    moveIsPossible();


private:
    QList<MyCircle*> balls;
    int clickedBallIndex = -1;
    char getRandomColorLetter();
};

#endif // BALLSLIST_H
