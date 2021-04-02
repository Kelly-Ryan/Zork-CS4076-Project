#include "exit.h"

Exit::Exit(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){

}

Exit::Exit(string direction){
    this->direction = direction;

    if(direction.compare("north") == 0){
        setPos(450,0);
        setPixmap(QPixmap(":/images/images/exit.png"));         //100px x 100px
    }

    else if(direction.compare("south") == 0){
        setPos(450,500);
        setPixmap(QPixmap(":/images/images/exit.png"));
    }

    else if(direction.compare("east") == 0){
        setPos(700,200);
        setPixmap(QPixmap(":/images/images/eastExit.png"));     //43px x 153px
    }

    else if(direction.compare("west") == 0){
        setPos(260,200);
        setPixmap(QPixmap(":/images/images/westExit.png"));     //43px x 153px
    }
}

string Exit::getDirection(){
    return direction;
}

Exit::~Exit(){

}
