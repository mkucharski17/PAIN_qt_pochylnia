#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include<QtGui>
#include<QGraphicsItem>
#include<QtMath>
#include"colors.h"
#include <QSequentialAnimationGroup>

class MyCircle : public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY (QPointF pos READ pos WRITE setPos)
public:
    MyCircle(double a, double b, double c, double d,char colorLetter, QGraphicsItem *parent);
    void select();
    void unselect();
    void move();
    int getIndex();
    void setCurrentIndex(int index);
    int getCurrentIndex();
    QPropertyAnimation* getAnimation();


signals:
    ballClicked(int);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QBrush getBrushFromLetter(char letter);
    int index;
    int currentIndex;
    QPropertyAnimation *animation = new QPropertyAnimation(this,"pos");



};

#endif // MYCIRCLE_H
