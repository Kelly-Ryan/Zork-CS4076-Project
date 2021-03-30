#include "exit.h"

#include <string>
#include <iostream>

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

using namespace std;

Exit::Exit(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){

}

Exit::Exit(string direction){
    if(direction.compare("north") == 0){
        setPos(450,0);
        setPixmap(QPixmap(":/images/images/exit.png"));
    }

    else if(direction.compare("south") == 0){
        setPos(450,500);
        setPixmap(QPixmap(":/images/images/exit.png"));
    }

    else if(direction.compare("east") == 0){
        setPos(700,200);
        setPixmap(QPixmap(":/images/images/eastExit.png"));
    }

    else if(direction.compare("west") == 0){
        setPos(260,200);
        setPixmap(QPixmap(":/images/images/westExit.png"));
    }
}

Exit::~Exit(){

}
