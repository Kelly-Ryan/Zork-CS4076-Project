#include "player.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){
    setFlag(QGraphicsItem::ItemIsFocusable);            //make player focusable
    setFocus();                                         //set focus on player
    setPixmap(QPixmap(":/images/images/player.png"));   //draw player
}

//overloaded constructor for creating new Player object in new Room
Player::Player(int xPos, int yPos, Game *game){
    setPos(xPos,yPos);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPixmap(QPixmap(":/images/images/player.png"));
    this->game = game;
}

void Player::keyPressEvent(QKeyEvent *event){       //player movement

    if(event->key() == Qt::Key_W){          //move north
        if(pos().y() > 75){
            setPos(x(), y() - speed);
            collision();
        }
    }
    else if(event->key() == Qt::Key_S){     //move south
        if(pos().y() + 51 < 525){
            setPos(x(), y() + speed);
            collision();
        }
    }
    else if(event->key() == Qt::Key_A){     //move west
        if(pos().x() > 285){
            setPos(x() - speed, y());
            collision();
        }
    }
    else if(event->key() == Qt::Key_D){     //move east
        if(pos().x() + 45 < 725){
            setPos(x() + speed, y());
            collision();
        }
    }
}

void Player::collision(){
    //list of pointers to all the QGraphicsItems that are colliding with the calling object (the player)
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //traverse this list and find out of the player is colliding with an object of type Exit
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(GameItem)){ //if of type item works but we need to make it generic
               qDebug() << "Collided with item";
               GameItem *item = (GameItem *)colliding_items[i];
               QMessageBox msg;
               msg.setWindowTitle("Item information");
               msg.setText("Do you want to add " + item->getDescription() + " to the inventory?");
               msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
               msg.setDefaultButton(QMessageBox::Yes);
               msg.setWindowFlags(Qt::FramelessWindowHint);
               msg.setStyleSheet("background-color:gray;border-style:outset");
               int response = msg.exec();

//               if(response == QMessageBox::Yes) emit itemCollected(item);
        }
        if(typeid(*(colliding_items[i])) == typeid(Exit)){
            Exit *currentExit = (Exit *)colliding_items[i];
            string direction = currentExit->getDirection();

            if(direction.compare("north") == 0){
                Room *nextRoom = game->currentRoom->nextRoom("north");
                if (nextRoom != NULL){              //check if this room has an exit in this direction
                    game->currentRoom->removeItem(this); //remove player item from room we're leaving
                    game->currentRoom = nextRoom;   //set new currentRoom
                    game->player = new Player(475,450, game);//set position of player in next room
                    nextRoom->addItem(game->player);    //add new player to new room
                    game->setScene(nextRoom);       //load scene for next room
                }
            }
            else if(direction.compare("south") == 0){
                Room *nextRoom = game->currentRoom->nextRoom("south");
                if (nextRoom != NULL){
                    game->currentRoom->removeItem(this);
                    game->currentRoom = nextRoom;
                    game->player = new Player(475,100, game);
                    nextRoom->addItem(game->player);
                    game->setScene(nextRoom);
                }
            }
            else if(direction.compare("east") == 0){
                Room *nextRoom = game->currentRoom->nextRoom("east");
                if (nextRoom != NULL){
                    game->currentRoom->removeItem(this);
                    game->currentRoom = nextRoom;
                    game->player = new Player(300,275, game);
                    nextRoom->addItem(game->player);
                    game->setScene(nextRoom);
                }
            }
            else if(direction.compare("west") == 0){
                Room *nextRoom = game->currentRoom->nextRoom("west");
                if (nextRoom != NULL){
                    game->currentRoom->removeItem(this);
                    game->currentRoom = nextRoom;
                    game->player = new Player(650,275, game);
                    nextRoom->addItem(game->player);
                    game->setScene(nextRoom);
                }
            }
        }
    }
}

Player::~Player(){

}
