#include "player.h"

#include <QKeyEvent>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){    //draw player
    setPixmap(QPixmap(":/images/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_W){
        if(pos().y() > 0){
            setPos(x(),y()-10);
        }
    }
    else if(event->key() == Qt::Key_S){
        if(pos().y() + 51 < 600){
            setPos(x(),y()+10);
        }
    }

    else if(event->key() == Qt::Key_A){
        if(pos().x() > 0){
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_D){
        if(pos().x() + 45 < 800){
            setPos(x()+10,y());
        }
    }
}

