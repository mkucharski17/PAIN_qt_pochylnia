#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    ramp = new Ramp();
    ballList = new BallsList(ramp);
    scene->addItem(ramp);


    QPushButton *btn = new QPushButton("Move");
    moveButton = new Movebutton(scene->addWidget(btn));

    connect(btn, &QPushButton::clicked, ballList,&BallsList::ballsMoving);
    connect(ballList,&BallsList::moveIsNotPossible,moveButton, &Movebutton::buttonDeactivate);

    connect(ballList,&BallsList::moveIsPossible,moveButton, &Movebutton::buttonActivate);
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNowa_gra_triggered()
{
    scene->clear();
    ramp = new Ramp();
    ballList = new BallsList(ramp);
    scene->addItem(ramp);


    QPushButton *btn = new QPushButton("Move");
    moveButton = new Movebutton(scene->addWidget(btn));

    connect(btn, &QPushButton::clicked, ballList,&BallsList::ballsMoving);
    connect(ballList,&BallsList::moveIsNotPossible,moveButton, &Movebutton::buttonDeactivate);
    connect(ballList,&BallsList::moveIsPossible,moveButton, &Movebutton::buttonActivate);
    ui->graphicsView->show();
}

void MainWindow::on_actionZako_cz_triggered()
{
    QApplication::exit();
}
