#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QtGui>
#include"ramp.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
void itemSelected();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<MyCircle*> balls;
    char getRandomColorLetter();

};
#endif // MAINWINDOW_H
