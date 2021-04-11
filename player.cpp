#include "weaponException.cpp"
#include "player.h"
#include "gamePopup.h"

#include <QKeyEvent>
#include <type_traits>
#include <typeinfo>

#include <iostream>

// dont ever use this constructor
Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
}

//overloaded constructor for creating new Player object
Player::Player(int xPos, int yPos, Game *game)
{
    setPos(xPos,yPos);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPixmap(QPixmap(":/images/images/player.png"));
    this->game = game;
    hitPoints = new Healthbar("Player",health);
    hitPoints->setPos(800,25);
}

void Player::keyPressEvent(QKeyEvent *event) //player movement
{
    if(event->key() == Qt::Key_W) //move north
    {
        if(pos().y() > 75)
        {
            setPos(x(), y() - SPEED);
            collision();
        }
    }
    else if(event->key() == Qt::Key_S)  //move south
    {
        if(pos().y() + 51 < 525)
        {
            setPos(x(), y() + SPEED);
            collision();
        }
    }
    else if(event->key() == Qt::Key_A)  //move west
    {
        if(pos().x() > 285)
        {
            setPos(x() - SPEED, y());
            collision();
        }
    }
    else if(event->key() == Qt::Key_D)      //move east
    {
        if(pos().x() + 45 < 725){
            setPos(x() + SPEED, y());
            collision();
        }
    }

    else if(event->key() == Qt::Key_Space){
        QList<QGraphicsItem *> colliding_items = collidingItems();

       try {
            qDebug() << "Space bar pressed";

            if(holding.getType() != WEAPON)
            {
                WeaponException e;
                throw e;
            }
        }
        catch (WeaponException &e)
        {
            e.what();
        }
        //traverse this list and find out of the player is colliding with an object of type Enemy

        for(int i = 0, n = colliding_items.size(); i < n; ++i){
            if(typeid(*(colliding_items[i])) == typeid(Enemy)){
                    Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);
                    qDebug() << "Launching attack on enemy with " << holding.inHand.weapon->itemInfo();
                    Zork::combat(holding.inHand.weapon,enemy);
                    if(enemy->isAlive())
                        enemy->getHealthbar()->updateHealth(enemy->getHealth());
            }
        }
    }
}

void Player::collision()
{
    //list of pointers to all the QGraphicsItems that are colliding with the calling object (the player)
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //traverse this list and find out of the player is colliding with an object of type Exit
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Treasure))
        {
            qDebug() << "Game Over";
            GamePopup msg;
            msg.setText("Congratulations you found the treasure.\nYour quest is now complete");
            msg.exec();
            exit(0);
        }

        if(typeid(*(colliding_items[i])) == typeid(HealthPotion) || typeid(*(colliding_items[i])) == typeid(Weapon) || typeid(*(colliding_items[i])) == typeid(RoomKey))
        {
               qDebug() << "Collided with item";
               GameItem *item = (GameItem *)colliding_items[i];
               GamePopup msg;
               msg.setText("Do you want to add " + item->getDescription() + " to the inventory/armoury?");
               msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
               msg.setDefaultButton(QMessageBox::Yes);

               int response = msg.exec();

               if(response == QMessageBox::Yes) emit itemCollected(item);
        }
        if(typeid(*(colliding_items[i])) == typeid(Exit))
        {
            Exit *currentExit = (Exit *)colliding_items[i];
            string direction = currentExit->getDirection();

            if(direction.compare("north") == 0)
            {
                Room *nextRoom = game->currentRoom->nextRoom("north");
                if (nextRoom != NULL) //check if this room has an exit in this direction
                {
                    game->currentRoom = nextRoom;   //set new currentRoom
                    nextRoom->addItem(game->player);    //add player to new room
                    setPos(475,450);                //set position of player
                    setFocus();

                    nextRoom->addItem(hitPoints);
                    game->setScene(nextRoom);       //load scene for next room
                }
            }
            else if(direction.compare("south") == 0)
            {
                Room *nextRoom = game->currentRoom->nextRoom("south");
                if (nextRoom != NULL)
                {
                    game->currentRoom = nextRoom;
                    nextRoom->addItem(game->player);
                    setPos(475,100);
                    setFocus();

                    nextRoom->addItem(hitPoints);
                    game->setScene(nextRoom);
                }
            }
            else if(direction.compare("east") == 0)
            {
                Room *nextRoom = game->currentRoom->nextRoom("east");
                if (nextRoom != NULL)
                {
                    if(nextRoom->getIsLocked())
                    {
                        if(nextRoom->getRoomName() == "Room G")     //if it is a locked room
                        {
                            if(holding.getType() != NULL)           //if the player is holding an item
                            {
                               if(holding.getType() == KEY && holding.inHand.key->getDescription() == "Silver Key")
                               {
                                   game->currentRoom = nextRoom;
                                   game->currentRoom->setIsLocked(false);    //permanently unlock room with key
                                   nextRoom->addItem(game->player);
                                   setPos(300,275);
                                   setFocus();

                                   nextRoom->addItem(hitPoints);
                                   game->setScene(nextRoom);
                               }
                               else
                               {
                                  GamePopup msg;
                                  msg.setText("Use the silver key to open this door!");
                                  msg.exec();
                               }
                            }
                           else
                            {
                              GamePopup msg;
                              msg.setText("Use the silver key to open this door!");
                              msg.exec();
                            }
                        }
                        else if(nextRoom->getRoomName() == "Room B")
                        {
                          if(holding.getType() != NULL)           //if the player is holding an item
                          {
                               if(holding.getType() == KEY && holding.inHand.key->getDescription() == "Gold Key")
                               {
                                    game->currentRoom = nextRoom;
                                    game->currentRoom->setIsLocked(false);    //permanently unlock room with key
                                    nextRoom->addItem(game->player);
                                    setPos(300,275);
                                    setFocus();

                                    nextRoom->addItem(hitPoints);
                                    game->setScene(nextRoom);
                                }
                                else
                                {
                                    GamePopup msg;
                                    msg.setText("Use the gold key to open this door!");
                                    msg.exec();
                                }
                            }
                            else
                            {
                                GamePopup msg;
                                msg.setText("Use the gold key to open this door!");
                                msg.exec();
                            }
                        }
                        else
                        {
                            game->currentRoom = nextRoom;
                            nextRoom->addItem(game->player);
                            setPos(300,275);
                            setFocus();

                            nextRoom->addItem(hitPoints);
                            game->setScene(nextRoom);
                        }
                    }
                    else
                    {
                        game->currentRoom = nextRoom;
                        nextRoom->addItem(game->player);
                        setPos(300,275);
                        setFocus();

                        nextRoom->addItem(hitPoints);
                        game->setScene(nextRoom);
                    }
                }
            }
            else if(direction.compare("west") == 0)
            {
                Room *nextRoom = game->currentRoom->nextRoom("west");
                if (nextRoom != NULL)
                {
                    if(nextRoom->getIsLocked())
                    {
                        if(nextRoom->getRoomName() == "Room H")     //if it is a locked room
                        {
                            if(holding.getType() != NULL)           //if the player is holding an item
                            {
                                if(holding.getType() == KEY && holding.inHand.key->getDescription() == "Bronze Key")
                                {

                                    game->currentRoom = nextRoom;
                                    game->currentRoom->setIsLocked(false);    //permanently unlock room with key
                                    nextRoom->addItem(game->player);
                                    setPos(650,275);
                                    setFocus();

                                    nextRoom->addItem(hitPoints);
                                    game->setScene(nextRoom);
                                }
                                else
                                {
                                    GamePopup msg;
                                    msg.setText("Use the bronze key to open this door!");
                                    msg.exec();
                                }
                            }
                            else
                            {
                                GamePopup msg;
                                msg.setText("Use the bronze key to open this door!");
                                msg.exec();
                            }
                        }
                        else
                        {
                            game->currentRoom = nextRoom;
                            nextRoom->addItem(game->player);
                            setPos(650,275);
                            setFocus();

                            nextRoom->addItem(hitPoints);
                            game->setScene(nextRoom);
                        }
                    }
                    else
                    {
                        game->currentRoom = nextRoom;
                        nextRoom->addItem(game->player);
                        setPos(650,275);
                        setFocus();

                        nextRoom->addItem(hitPoints);
                        game->setScene(nextRoom);
                    }
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
    return hitPoints;
}

void Player::equipPlayer(GameItem *itemSelected)
{
    if(typeid(*itemSelected) == typeid(Weapon))
    {
        Weapon* weapon = dynamic_cast<Weapon*>(itemSelected);
        holding.inHand.weapon = weapon;
        holding.setType(WEAPON);

    }
    else if(typeid(*itemSelected) == typeid(RoomKey))
    {
        RoomKey* key = dynamic_cast<RoomKey*>(itemSelected);
        holding.inHand.key = key;
        holding.setType(KEY);
    }
    else
    {
        HealthPotion *potion = dynamic_cast<HealthPotion*>(itemSelected);
        if(health < MAX_HEALTH)
        {
            health += potion->getBonus();
            hitPoints->updateHealth(health);
            potion->setOutOfUse(true);
        }
        else
        {
            GamePopup msg;
            msg.setText("You are currently at full health");
            msg.setInformativeText("If you are attacked by an enmy use this potion to restore your health");
            msg.exec();
        }
    }
}

void Player::defeated()
{
    clearFocus();
    GamePopup gameOver;
    gameOver.setText("You loose game over");
    gameOver.exec();
    exit(0);
}

Player::~Player()
{
    delete game;
    delete hitPoints;
}
