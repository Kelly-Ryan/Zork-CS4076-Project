#include "exit.h"
#include "player.h"

#include <QDebug>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){
    //draw player
    setPixmap(QPixmap(":/images/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    int speed = 10;

    if(event->key() == Qt::Key_W){
        if(pos().y() > 50){
            setPos(x(), y() - speed);
            qDebug() << exitInteraction();
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

bool Player::exitInteraction(){
    //list of pointers to all the QGraphicsItems that are colliding with the calling object (the player)
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //traverse this list and find out of the player is colliding with an exit
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Exit)){
            //set QGraphicsScene in QGraphicsView
            return true;
        }
    }
    return false;
}

Player::~Player(){
}
