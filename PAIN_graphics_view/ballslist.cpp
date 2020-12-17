#include "ballslist.h"

BallsList::BallsList(QGraphicsItem *parent)
{
    for(int i = 0 ; i < 1000 ; i+=50)
    {
        MyCircle* ball = new MyCircle(i,-0.3*i+300 -60,51.0,50.0,getRandomColorLetter(),parent);
        connect(ball,&MyCircle::ballClicked,this,&BallsList::ballSelected);
        balls.append(ball);
    }
}

QList<MyCircle*> BallsList::getBalls(){
    return this->balls;
}

void BallsList::ballSelected(int clickedIndex)
{
    if(clickedBallIndex != -1)
    for(int j = -1 ; j < 2 ;j++)
       balls.at(clickedBallIndex+j)->unselect();
    //zaznaczamy nowe jesli nie są skrajne
    if(clickedIndex > 0 && clickedIndex < balls.size()-1)
    {
        for(int j = -1 ; j < 2 ;j++)
           ( balls.at(clickedIndex+j))->select();

        clickedBallIndex = clickedIndex;
        emit moveIsPossible();

    }
    // jest skrajne wiec nie da rady sie ruszyc
    else
        emit moveIsNotPossible();
}

void BallsList::ballsMoving(){
        int index = clickedBallIndex;

    for(int i = 0 ; i < 3; i++){
        balls.append(balls.at(index-1));
        balls.last()->setIndex(balls.size()-4+i);
        balls.at(index-1)->unselect();
        balls.removeAt(index-1);

   }
    balls.at(balls.size()-2)->setSelected(false);
    for(int i = index-1 ; i < balls.size()-3; ++i)
    {
        balls.at(i)->setIndex(i);}

    for(int i = index-1 ; i < balls.size(); i++)
        balls.at(i)->move(index);

    emit moveIsNotPossible();
    clickedBallIndex = -1;
}

char BallsList::getRandomColorLetter(){
    int randomValue = qrand() % 3;
    switch (randomValue){
        case 0 : return 'R';
        case 1 : return 'G';
        case 2 : return 'B';
    }
}
