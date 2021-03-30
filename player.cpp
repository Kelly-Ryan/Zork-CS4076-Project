#include "exit.h"
#include "game.h"
#include "player.h"

#include <QDebug>
#include <QKeyEvent>

extern Game *game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){
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

    //move north
    if(event->key() == Qt::Key_W){
        if(pos().y() > 75){
            setPos(x(), y() - speed);

           //check for exits
            if(exitCollision()){
                Room *nextRoom = game->currentRoom->nextRoom("north");
                if (nextRoom != NULL){              //check if this room has an exit in this direction
                    game->currentRoom->removeItem(game->player); //remove player item from room we're leaving
                    game->currentRoom = nextRoom;   //set new currentRoom
                    game->player = new Player(450,450);//set position of player in next room
                    nextRoom->addItem(game->player);
                    game->setScene(nextRoom);       //load scene for next room
                }
            }
        }
    }
    else if(event->key() == Qt::Key_S){
        if(pos().y() + 51 < 525){
            setPos(x(), y() + speed);

            //check for exits
             if(exitCollision()){
                 Room *nextRoom = game->currentRoom->nextRoom("south");
                 if (nextRoom != NULL){
                     game->currentRoom->removeItem(game->player);
                     game->currentRoom = nextRoom;
                     game->player = new Player(450,150);
                     nextRoom->addItem(game->player);
                     game->setScene(nextRoom);
                 }
             }
        }
    }
    else if(event->key() == Qt::Key_A){
        if(pos().x() > 275){
            setPos(x() - speed, y());

            //check for exits
             if(exitCollision()){
                 Room *nextRoom = game->currentRoom->nextRoom("east");
                 if (nextRoom != NULL){
                     game->currentRoom->removeItem(game->player);
                     game->currentRoom = nextRoom;
                     game->player = new Player(350,350);
                     nextRoom->addItem(game->player);
                     game->setScene(nextRoom);
                 }
             }
        }
    }
    else if(event->key() == Qt::Key_D){
        if(pos().x() + 45 < 725){
            setPos(x() + speed, y());

            //check for exits
             if(exitCollision()){
                 Room *nextRoom = game->currentRoom->nextRoom("west");
                 if (nextRoom != NULL){
                     game->currentRoom->removeItem(game->player);
                     game->currentRoom = nextRoom;
                     game->player = new Player(650,350);
                     nextRoom->addItem(game->player);
                     game->setScene(nextRoom);
                 }
             }
        }
    }
}

bool Player::exitCollision(){
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
