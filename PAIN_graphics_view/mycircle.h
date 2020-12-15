#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include<QtCore>
#include<QtGui>
#include<QGraphicsItem>
#include<QtMath>
#include"colors.h"

class MyCircle : public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY (QPointF pos READ pos WRITE setPos)
public:
    MyCircle(double a, double b, double c, double d,char colorLetter, QGraphicsItem *parent);
    void select();
    void unselect();
    void move();
//    void moveDown();
public slots:
    void setClickedIndex(int index);


private:
    QBrush getBrushFromLetter(char letter);
    QPropertyAnimation *animation;
    int index;
    int clickedIndex;
    bool movable = true;
};

#endif // MYCIRCLE_H
