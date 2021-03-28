#include "player.h"

#include <QKeyEvent>
#include <math.h>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){
    //draw player
    setPixmap(QPixmap(":/images/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    int speed = 10;

    if(event->key() == Qt::Key_W){
        if(pos().y() > 100){
            setPos(x(), y() - speed);
        }
    }
    else if(event->key() == Qt::Key_S){
        if(pos().y() + 51 < 500){
            setPos(x(), y() + speed);
        }
    }
    else if(event->key() == Qt::Key_A){
        if(pos().x() > 300){
            setPos(x() - speed, y());
        }
    }
    else if(event->key() == Qt::Key_D){
        if(pos().x() + 45 < 700){
            setPos(x() + speed, y());
        }
    }
}

Player::~Player(){
}
