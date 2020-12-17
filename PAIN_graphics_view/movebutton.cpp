#include "movebutton.h"

Movebutton::Movebutton(QGraphicsProxyWidget *proxy)
{
    this->proxy = proxy;
    proxy->setPos(100,-100);
    proxy->setEnabled(false);
}

void Movebutton::buttonActivate()
{
    if(!proxy->isEnabled())
    proxy->setEnabled(true);
}

void Movebutton::buttonDeactivate()
{
    if(proxy->isEnabled())
    proxy->setEnabled(false);
}

QGraphicsProxyWidget* Movebutton::getProxy()
{
    return proxy;
}
