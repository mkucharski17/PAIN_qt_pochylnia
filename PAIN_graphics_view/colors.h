#ifndef COLORS_H
#define COLORS_H

#endif // COLORS_H
#include <iostream>
#include <QtCore>
using namespace std;

class Color{
public:
    Color(char colorLetter){
        switch(colorLetter){
        case 'R' : color = Qt::red;
            break;
        case 'G' : color = Qt::green;
            break;
        case 'B' : color = Qt::blue;
            break;
        }
    }

    Qt::GlobalColor getColor(){
       return color;
    }

private:
    Qt::GlobalColor color;
};
