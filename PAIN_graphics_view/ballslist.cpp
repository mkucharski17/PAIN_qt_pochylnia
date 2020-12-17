#include "ballslist.h"

BallsList::BallsList(QGraphicsItem *parent)
{
    for(int i = 0 ; i < 1000 ; i+=50)
    {
        MyCircle* ball = new MyCircle(i,-0.3*i+300 -60,51.0,50.0,getRandomColorLetter(),parent);
        connect(ball,&MyCircle::ballClicked,this,&BallsList::ballSelected);
        connect(ball->getAnimation(),&QSequentialAnimationGroup::finished, this,&BallsList::ballsAfterMoving);
        balls.append(ball);
    }
}

QList<MyCircle*> BallsList::getBalls(){
    return this->balls;
}

void BallsList::ballSelected(int clickedIndex)
{
    //czyscimy zaznaczenie jesli było
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

    for(int i = -1 ; i < 2; i++){
        balls.at(clickedBallIndex+i)->setCurrentIndex(balls.size()-2+i);
        balls.at(clickedBallIndex+i)->unselect();
   }
    balls.at(clickedBallIndex)->setSelected(false);

    for(int i = clickedBallIndex+2 ; i < balls.size(); ++i)
    {
        balls.at(i)->setCurrentIndex(i-3);}
    emit moveIsNotPossible();

    for(int i = clickedBallIndex-1 ; i < balls.size(); i++)
        balls.at(i)->move();


}

void BallsList::ballsAfterMoving(){
    qSort(balls.begin(), balls.end(),
          []( MyCircle *a,  MyCircle* b) -> bool { return a->getCurrentIndex() < b->getCurrentIndex(); });
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
