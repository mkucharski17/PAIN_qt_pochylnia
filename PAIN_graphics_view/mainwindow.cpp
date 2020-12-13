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


    moveButton = scene->addWidget(new QPushButton("Move"));
    moveButton->setPos(100,-100);
    moveButton->setEnabled(false);

    for(int i = 0 ; i < 1000 ; i+=50)
    {
        MyCircle *ball = new MyCircle(i,(-0.3*i+300 -60),51.0,50.0,getRandomColorLetter(),ramp);
        balls.append(ball);
        ball->setFlag(QGraphicsItem::ItemIsSelectable , true);
    }
    connect(scene, &QGraphicsScene::selectionChanged, this, &MainWindow::itemSelected);


}

MainWindow::~MainWindow()
{
    delete ui;
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

        int indexfClickedBall = balls.indexOf(ball);
        if(clickedIndex != -1)
            for(int j = -1 ; j < 2 ;j++)
            {
                balls.at(clickedIndex+j)->unselect();
            }

        if(indexfClickedBall > 0 && indexfClickedBall < balls.length()-1)
        {
            if(!moveButton->isEnabled())
                moveButton->setEnabled(true);



            for(int j = -1 ; j < 2 ;j++)
                balls.at(indexfClickedBall+j)->select();

            clickedIndex = indexfClickedBall;
        }
      else if(moveButton->isEnabled())
        moveButton->setEnabled(false);
    }
}


