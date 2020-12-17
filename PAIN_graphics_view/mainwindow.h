#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QtGui>
#include<QPushButton>
#include <QGraphicsView>
#include<QGraphicsProxyWidget>
#include<QPropertyAnimation>
#include <QSignalMapper>
#include <QEvent>
#include <QtGlobal>

#include"ramp.h"
#include"ballslist.h"
#include"movebutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getClickedIndex();

signals:
    void clickedIndexChanged(MyCircle *ball);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    BallsList *ballList;
    Movebutton *moveButton;
    Ramp* ramp ;

};
#endif // MAINWINDOW_H
