#include "exit.h"

#include <string>
#include <iostream>

using namespace std;

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

Exit::Exit(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){

}

void Exit::setExitImage(string direction){
    if(direction.compare("north") || direction.compare("south")){
        setPixmap(QPixmap(":/images/images/exit.png"));
    }
    else  if(direction.compare("east")){
        setPixmap(QPixmap(":/images/images/eastExit.png"));
    }
    else  if(direction.compare("west") ){
        setPixmap(QPixmap(":/images/images/westExit.png"));
    }
}

Exit::~Exit(){

}
