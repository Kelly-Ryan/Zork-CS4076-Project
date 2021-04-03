#include "game.h"
#include "exit.h"

#include <string>
#include <iostream>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

using namespace std;

Game::Game(QWidget *){
    //set size of QGraphicsView and remove scroll bars
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setWindowTitle(QString::fromStdString(::gameTitle));
    setFixedSize(1000,600);

    createRooms();
    currentRoom = a;            //set current room/scene

    player = new Player(475, 275, this);  //position player in centre of room
    a->addItem(player);         //add player to scene

    inventory = new Inventory;
    connect(player,SIGNAL(itemCollected(GameItem *)),inventory,SLOT(addToInventory(GameItem*)));
    connect(inventory,SIGNAL(itemAdded(GameItem *)),this,SLOT(removeFromRoom(GameItem *)));
    inventory->show();

    monster = new Enemy("monster",3,":/images/images/monster.png");
    a->addItem(monster);

    Item *item2 = new Item("iPhone",400,3,":/images/images/phone.png");
    item2 -> setPos(200,200);
    a -> addItem(item2);

    Weapon * weapon = new Weapon("sword",10,2,":/images/images/sword.png");
    weapon->setPos(400,300);
    a->addItem(weapon);
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

void Game::printHelp(){
    cout << "Help" << endl;
    //help text
}

void Game::removeFromRoom(GameItem *item)
{
    item->hide();
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


