#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QtGui>
#include<QPushButton>
#include<QGraphicsProxyWidget>
#include<QPropertyAnimation>
#include <QSignalMapper>
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
    int getClickedIndex();

public slots:
void itemSelected();


signals:
    void clickedIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<MyCircle*> balls;
    QGraphicsProxyWidget *moveButton;
    QPropertyAnimation *animation;
    int clickedIndex = -1;
    char getRandomColorLetter();
    QSignalMapper *signalMapper;

};
#endif // MAINWINDOW_H
