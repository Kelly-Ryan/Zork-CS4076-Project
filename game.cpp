#include "game.h"
#include "exit.h"

#include <string>
#include <iostream>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

using namespace std;

class QMenu;
class QContextMenuEvent;

Game::Game(QWidget *){
    //set size of QGraphicsView and remove scroll bars
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setFixedSize(1000,600);

    createRooms();
    currentRoom = a;            //set current room/scene

    player = new Player(475, 275, this);  //position player in centre of room
    a->addItem(player);         //add player to scene
    a->addItem(player->getHealthbar());

    armoury = new Inventory<Weapon>("Armoury",1);
    potions = new Inventory<HealthPotion>("Potions");

    connect(player,SIGNAL(itemCollected(GameItem *)),potions,SLOT(addToInventory(GameItem*)));
    connect(player,SIGNAL(healthPotion()),potions,SLOT(removeFromInventory()));
    connect(potions,SIGNAL(itemAdded(GameItem *)),this,SLOT(removeFromRoom(GameItem *)));
    connect(potions,SIGNAL(itemSelected(GameItem *)),player,SLOT(equipPlayer(GameItem *)));
    connect(potions,SIGNAL(restoreFocus()),this,SLOT(enableMovement()));

    connect(player,SIGNAL(itemCollected(GameItem *)),armoury,SLOT(addToInventory(GameItem*)));
    connect(armoury,SIGNAL(itemAdded(GameItem *)),this,SLOT(removeFromRoom(GameItem *)));
    connect(armoury,SIGNAL(itemSelected(GameItem *)),player,SLOT(equipPlayer(GameItem *)));
    connect(armoury,SIGNAL(restoreFocus()),this,SLOT(enableMovement()));

    potions->setPosition(760,420);
    armoury->setPosition(760,170);

    monster = new Enemy("monster",1,":/images/images/monster.png");
    a->addItem(monster);
    a->addItem(monster->getHealthbar());


    Weapon *weapon = new Weapon("sword",2,":/images/images/sword.png");
    Weapon *sword = new Weapon("special sword",2,":/images/images/sword.png");
    HealthPotion *oneLife = new HealthPotion(":/images/images/1Life.png",1);

    GameItem * roomAItems[] = {weapon,sword,oneLife};
    a->populateRoom(roomAItems,3);
    setScene(a);        //set first scene (room) in QGraphicsView
    show(); //show QGraphicsView
}

void Game::createRooms(){
    a = new Room("Room A", QImage(":images/images/stoneRoom.png"));
    b = new Room("Room B", QImage(":images/images/stoneRoom.png"));
    c = new Room("Room C", QImage(":images/images/stoneRoom.png"));
    d = new Room("Room D", QImage(":images/images/stoneRoom.png"));
    e = new Room("Room E", QImage(":images/images/stoneRoom.png"));
    f = new Room("Room F", QImage(":images/images/stoneRoom.png"));
    g = new Room("Room G", QImage(":images/images/stoneRoom.png"));
    h = new Room("Room H", QImage(":images/images/stoneRoom.png"));
    i = new Room("Room I", QImage(":images/images/stoneRoom.png"));

    //         (N, S, E, W)
    a->setExits(f, d, b, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, NULL, a, NULL);
    d->setExits(a, NULL, e, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, a, g, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, NULL, f, NULL);
    i->setExits(NULL, NULL, d, NULL);
}

void Game::printWelcome(){
    cout << "Welcome" << endl;
    //welcome message
}

void Game::help(){

}

void Game::removeFromRoom(GameItem *item)
{
    item->hide();
}

void Game::enableMovement()
{
    activateWindow();
    player->setFocus();
}

Game::~Game(){
    delete player;
    delete currentRoom;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
    delete i;
}
