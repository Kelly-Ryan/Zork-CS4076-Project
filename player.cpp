#include "player.h"

#include <QKeyEvent>
#include <QMessageBox>

// dont ever use this constructor
Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){
}

//overloaded constructor for creating new Player object
Player::Player(int xPos, int yPos, Game *game){
    setPos(xPos,yPos);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPixmap(QPixmap(":/images/images/player.png"));
    this->game = game;
    lives = new Healthbar("Player",health);
    lives->setPos(800,25);
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
    else if(event->key() == Qt::Key_Space){
        qDebug() << "Space bar pressed";
        QList<QGraphicsItem *> colliding_items = collidingItems();

        //traverse this list and find out of the player is colliding with an object of type Exit
        for(int i = 0, n = colliding_items.size(); i < n; ++i){
            if(typeid(*(colliding_items[i])) == typeid(Enemy) && typeid(*itemHolding) == typeid(Weapon)){
                    qDebug() << "Launching attack on enemy";
                    Weapon* weapon = dynamic_cast<Weapon*>(itemHolding);
                    Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);
                    combat(weapon,enemy);
                    enemy->getHealthbar()->updateHealth(enemy->getHealth());
            }
        }
    }
}

void Player::collision(){
    //list of pointers to all the QGraphicsItems that are colliding with the calling object (the player)
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //traverse this list and find out of the player is colliding with an object of type Exit
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Item) || typeid(*(colliding_items[i])) == typeid(Weapon)){ //if of type item works but we need to make it generic
               qDebug() << "Collided with item";
               GameItem *item = (GameItem *)colliding_items[i];
               QMessageBox msg;
               msg.setText("Do you want to add " + item->getDescription() + " to the inventory?");
               msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
               msg.setDefaultButton(QMessageBox::Yes);
               msg.setWindowFlags(Qt::FramelessWindowHint);
               msg.setStyleSheet("background-color:gray;border-style:outset");
               msg.move(350,300);
               int response = msg.exec();

               if(response == QMessageBox::Yes) emit itemCollected(item);
        }
        if(typeid(*(colliding_items[i])) == typeid(Exit)){
            Exit *currentExit = (Exit *)colliding_items[i];
            string direction = currentExit->getDirection();

            if(direction.compare("north") == 0){
                Room *nextRoom = game->currentRoom->nextRoom("north");
                if (nextRoom != NULL){              //check if this room has an exit in this direction
                    game->currentRoom = nextRoom;   //set new currentRoom
                    nextRoom->addItem(game->player);    //add player to new room
                    setPos(475,450);                //set position of player
                    setFocus();

                    nextRoom->addItem(lives);
                    game->setScene(nextRoom);       //load scene for next room
                }
            }
            else if(direction.compare("south") == 0){
                Room *nextRoom = game->currentRoom->nextRoom("south");
                if (nextRoom != NULL){
                    game->currentRoom = nextRoom;
                    nextRoom->addItem(game->player);
                    setPos(475,100);
                    setFocus();

                    nextRoom->addItem(lives);
                    game->setScene(nextRoom);
                }
            }
            else if(direction.compare("east") == 0){
                Room *nextRoom = game->currentRoom->nextRoom("east");
                if (nextRoom != NULL){
                    game->currentRoom = nextRoom;
                    nextRoom->addItem(game->player);
                    setPos(300,275);
                    setFocus();

                    nextRoom->addItem(lives);
                    game->setScene(nextRoom);
                }
            }
            else if(direction.compare("west") == 0){
                Room *nextRoom = game->currentRoom->nextRoom("west");
                if (nextRoom != NULL){
                    game->currentRoom = nextRoom;
                    nextRoom->addItem(game->player);
                    setPos(650,275);
                    setFocus();

                    nextRoom->addItem(lives);
                    game->setScene(nextRoom);
                }
            }
        }
    }
}

int Player::getHealth()
{
    return health;
}

void operator+(Enemy &enemy,Player &player)
{
    player.health -= enemy.getDamage();
    if(player.health <= 0)
    {
        player.alive = false;
    }
}

bool Player::isAlive()
{
    return alive;
}

Healthbar *Player::getHealthbar()
{
    return lives;
}

void Player::equipPlayer(GameItem *item)
{
    itemHolding = item;
}

GameItem * Player::getItemHolding()
{
    return itemHolding;
}

Player::~Player(){
    delete game;
    delete lives;
}
