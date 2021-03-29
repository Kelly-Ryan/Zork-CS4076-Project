#include "exit.h"
#include "game.h"
#include "player.h"

#include <QDebug>
#include <QKeyEvent>

extern Game *game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){
    setPos(500,300);                                    //set position of player
    setFlag(QGraphicsItem::ItemIsFocusable);            //make player focusable
    setFocus();                                         //set focus on player
    setPixmap(QPixmap(":/images/images/player.png"));   //draw player
}

Player::Player(int xPos, int yPos){
    setPos(xPos,yPos);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPixmap(QPixmap(":/images/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    int speed = 10;

    if(event->key() == Qt::Key_W){
        if(pos().y() > 75){
            setPos(x(), y() - speed);
            //qDebug() << exitInteraction();
            if(exitInteraction()){
                //room 2 scene
                QGraphicsScene *room2scene = new QGraphicsScene();
                room2scene->setSceneRect(0,0,1000,600);           //set scene dimensions
                room2scene->setBackgroundBrush(QBrush(QImage(":/images/images/room2.png")));

                string direction = "south";
                string *dirPtr = &direction;
                Exit *exit = new Exit(dirPtr);
                room2scene->addItem(exit);

                Player *player = new Player(450,450);
                room2scene->addItem(player);

                game->changeRoom(room2scene);
            }
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
