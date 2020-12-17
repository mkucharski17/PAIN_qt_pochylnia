#ifndef MOVEBUTTON_H
#define MOVEBUTTON_H

#include <QGraphicsProxyWidget>
#include <QPushButton>

class Movebutton: public QObject
{
    Q_OBJECT
public:
    Movebutton(QGraphicsProxyWidget *);
    QGraphicsProxyWidget *getProxy();

public slots:
    void buttonActivate();
    void buttonDeactivate();
private:
     QGraphicsProxyWidget *proxy;

};

#endif // MOVEBUTTON_H
