#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    for(int i = -250 ; i < 250 ; i+=50)
    {
        circle = new MyCircle(i,0,50,50,Qt::red);
        scene->addItem(circle);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

