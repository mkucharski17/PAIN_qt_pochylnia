#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    Ramp* ramp = new Ramp();
    scene->addItem(ramp);

    QPushButton *btn = new QPushButton("Move");
    moveButton = scene->addWidget(btn);
    moveButton->setPos(100,-100);
    moveButton->setEnabled(false);
    signalMapper = new QSignalMapper(this);



    for(int i = 0 ; i < 1000 ; i+=50)
    {
        MyCircle *ball = new MyCircle(i,(-0.3*i+300 -60),51.0,50.0,getRandomColorLetter(),ramp);
        balls.append(ball);
        ball->setFlag(QGraphicsItem::ItemIsSelectable , true);
        connect(this ,&MainWindow::clickedIndexChanged,ball, &MyCircle::setClickedIndex);
        connect(btn, &QPushButton::clicked, ball,&MyCircle::move);
    }

    connect(scene, &QGraphicsScene::selectionChanged, this, &MainWindow::itemSelected);

}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::getClickedIndex()
{
    return this->clickedIndex;
}

char MainWindow::getRandomColorLetter(){
    int randomValue = qrand() % 3;
    switch (randomValue){
        case 0 : return 'R';
        case 1 : return 'G';
        case 2 : return 'B';
    }
}

void MainWindow::itemSelected()
{
    if(!scene->selectedItems().isEmpty())
    {
        MyCircle *ball = qgraphicsitem_cast<MyCircle *>(scene->selectedItems().first());

        int indexOfClickedBall = balls.indexOf(ball);
        if(clickedIndex != -1)
            for(int j = -1 ; j < 2 ;j++)
            {
                balls.at(clickedIndex+j)->unselect();
            }

        if(indexOfClickedBall > 0 && indexOfClickedBall < balls.length()-1)
        {
            if(!moveButton->isEnabled())
                moveButton->setEnabled(true);

            for(int j = -1 ; j < 2 ;j++)
                balls.at(indexOfClickedBall+j)->select();

            clickedIndex = indexOfClickedBall;
            emit clickedIndexChanged(clickedIndex);
        }
      else if(moveButton->isEnabled())
        moveButton->setEnabled(false);
    }
}

////todo zrob aby animacja działała dla wielu na raz
//void MainWindow::itemsMoved(){

//}


