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

    for(int i = 0 ; i < 1000 ; i+=50)
    {   MyCircle *ball = new MyCircle(i,(-0.3*i+300 -60),51.0,50.0,getRandomColorLetter(),ramp);
        balls.append(ball);
        scene->addItem(ball);
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
    MyCircle *ball = qgraphicsitem_cast<MyCircle *>(scene->selectedItems().first());
    for(int i = 0 ; i < balls.length() ; i++){
        balls[i]->setBrush(QBrush(balls[i]->getColor().getColor()));
    }
    int indexfClickedBall = balls.indexOf(ball);

    if(indexfClickedBall > 2 || indexfClickedBall< balls.length()-3)
        for(int j = -1 ; j < 2 ;j++)
            balls.at(indexfClickedBall+j)->setBrush(QBrush(Qt::yellow));
}


