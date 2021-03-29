#include "exit.h"

#include <string>
#include <iostream>

using namespace std;

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

Exit::Exit(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){

}

Exit::Exit(string *dir){
    string direction = *dir;

    if(direction.compare("north") == 0){
        setPos(450,0);
        setPixmap(QPixmap(":/images/images/exit.png"));
    }

    if(direction.compare("south") == 0){
        setPos(450,500);
        setPixmap(QPixmap(":/images/images/exit.png"));
    }

    if(direction.compare("east") == 0){
        setPos(700,200);
        setPixmap(QPixmap(":/images/images/eastExit.png"));
    }

    if(direction.compare("west") == 0){
        setPos(260,200);
        setPixmap(QPixmap(":/images/images/westExit.png"));
    }
}

Exit::~Exit(){

}
