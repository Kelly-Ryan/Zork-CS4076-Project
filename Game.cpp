#include "Game.h"
#include "Exit.h"

#include <string>
#include <iostream>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

using namespace std;

Game::Game(QWidget *){
    //set size of QGraphicsView and remove scroll bars
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setFixedSize(1000,600);
    setWindowTitle(QString::fromStdString(::gameTitle));

    inventory = new Inventory;
//    inventory -> move(width()- 300,height()- 300); needs to be positioned and made static and possibly unclosable
    inventory->show();
    connect(inventory,SIGNAL(itemCollected(GameItem *)),this,SLOT(removeFromRoom(GameItem *)));

    createRooms();
    currentRoom = a;            //set current room/scene

    player = new Player(475, 275);   //position player in centre of room
    a->addItem(player);         //add player to scene

    monster = new Enemy("monster",":/images/monster.png");

    connect(player,SIGNAL(defeatedEnemy(Enemy *)),this,SLOT(removeEnemy(Enemy *)));

    Item *item2 = new Item("iPhone",400,3,":/images/phone.webp");
    item2 -> setPos(100,100);
    a -> addItem(item2);
    connect(item2,SIGNAL(itemSelected(GameItem *)),inventory,SLOT(addToInventory(GameItem*)));

    weapon = new Weapon("sword",10.5,1,":/images/sword.png");
    weapon -> setPos(200,200);
    a -> addItem(weapon);
    connect(weapon,SIGNAL(itemSelected(GameItem *)),inventory,SLOT(addToInventory(GameItem*)));

    setScene(a);        //set first scene (room) in QGraphicsView
    a->addItem(monster);
    show(); //show QGraphicsView

}

void Game::createRooms(){
    a = new Room("Room A", QImage(":/images/stoneRoom.png"));
    b = new Room("Room B", QImage(":/images/stoneRoom.png"));
    c = new Room("Room C", QImage(":/images/stoneRoom.png"));
    d = new Room("Room D", QImage(":/images/stoneRoom.png"));
    e = new Room("Room E", QImage(":/images/stoneRoom.png"));
    f = new Room("Room F", QImage(":/images/stoneRoom.png"));
    g = new Room("Room G", QImage(":/images/stoneRoom.png"));
    h = new Room("Room H", QImage(":/images/stoneRoom.png"));
    i = new Room("Room I", QImage(":/images/stoneRoom.png"));

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

void Game::printHelp(){
    cout << "Help" << endl;
    //help text
}

void Game::removeEnemy(Enemy *enemy)
{
   delete enemy;
}

void Game::removeFromRoom(GameItem *item)
{
    item->hide();
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


