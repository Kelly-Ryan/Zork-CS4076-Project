#include "game.h"
#include "exit.h"

#include <string>
#include <iostream>

using namespace std;

class QMenu;
class QContextMenuEvent;

Game::Game(QWidget *)
{
    //set size of QGraphicsView and remove scroll bars
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setFixedSize(1000,600);

    playlist -> addMedia(QUrl("qrc:/sounds/sounds/makai-symphony-dragon-slayer.mp3"));
    playlist -> setPlaybackMode(QMediaPlaylist::Loop);
    mediaPlayer -> setPlaylist(playlist);
    //mediaPlayer -> play();

    createRooms();
    currentRoom = stoneRoom;            //set current room/scene

    player = new Player(475, 275, this);  //position player in centre of room
    stoneRoom->addItem(player);         //add player to scene
    stoneRoom->addItem(player->getHealthbar());

    armoury = new Inventory<Weapon>("Armoury");
    potions = new Inventory<HealthPotion>("Potions",1);
    keys = new Inventory<RoomKey>("Keys",3);

    connect(player,SIGNAL(itemCollected(GameItem *)),potions,SLOT(addToInventory(GameItem*)));
    connect(potions,SIGNAL(itemAdded(GameItem *)),this,SLOT(removeFromRoom(GameItem *)));
    connect(potions,SIGNAL(itemSelected(GameItem *)),player,SLOT(equipPlayer(GameItem *)));
    connect(potions,SIGNAL(restoreFocus()),this,SLOT(enableMovement()));

    connect(player,SIGNAL(itemCollected(GameItem *)),armoury,SLOT(addToInventory(GameItem*)));
    connect(armoury,SIGNAL(itemAdded(GameItem *)),this,SLOT(removeFromRoom(GameItem *)));
    connect(armoury,SIGNAL(itemSelected(GameItem *)),player,SLOT(equipPlayer(GameItem *)));
    connect(armoury,SIGNAL(restoreFocus()),this,SLOT(enableMovement()));

    connect(player,SIGNAL(itemCollected(GameItem *)),keys,SLOT(addToInventory(GameItem*)));
    connect(keys,SIGNAL(itemAdded(GameItem *)),this,SLOT(removeFromRoom(GameItem *)));
    connect(keys,SIGNAL(itemSelected(GameItem *)),player,SLOT(equipPlayer(GameItem *)));
    connect(keys,SIGNAL(restoreFocus()),this,SLOT(enableMovement()));

    potions->setPosition(760,370);
    armoury->setPosition(760,170);
    keys->setPosition(760,600);

    monster = new Enemy("monster",1,":/images/images/monster.png");
    stoneRoom->addItem(monster);
    stoneRoom->addItem(monster->getHealthbar());

    Weapon *weapon = new Weapon("sword",2,":/images/images/sword.png");
    Weapon *sword = new Weapon("special sword",2,":/images/images/sword.png");
    HealthPotion *oneLife = new HealthPotion(":/images/images/1Life.png",1);
    HealthPotion *twoLives = new HealthPotion(":/images/images/2Lives.png",2);

    GameItem * roomAItems[] = {weapon,sword,oneLife,twoLives};
    stoneRoom->populateRoom(roomAItems,4);
    setScene(stoneRoom);        //set first scene (room) in QGraphicsView
    show(); //show QGraphicsView
}

void Game::createRooms()
{
                        //room name, background image, isLocked
    stoneRoom = new Room("Stone Room", QImage(":images/images/stoneRoom.png"), false);
    b = new Room("Room B", QImage(":images/images/stoneRoom.png"), true);
    c = new Room("Room C", QImage(":images/images/stoneRoom.png"), false);
    d = new Room("Room D", QImage(":images/images/stoneRoom.png"), false);
    e = new Room("Room E", QImage(":images/images/stoneRoom.png"), false);
        RoomKey *bronzeKey = new RoomKey("Bronze Key",":images/images/bronze-key.png");
        e->addItem(bronzeKey);
        bronzeKey->setPos(500,300);
    f = new Room("Room F", QImage(":images/images/stoneRoom.png"), false);
    g = new Room("Room G", QImage(":images/images/stoneRoom.png"), true);
        RoomKey *goldKey = new RoomKey("Gold Key",":images/images/gold-key.png");
        g->addItem(goldKey);
        goldKey->setPos(500,300);
    h = new Room("Room H", QImage(":images/images/stoneRoom.png"), true);
        RoomKey *silverKey = new RoomKey("Silver Key",":images/images/silver-key.png");
        h->addItem(silverKey);
        silverKey->setPos(500,300);
    i = new Room("Room I", QImage(":images/images/stoneRoom.png"), false);

    //         (N, S, E, W)
    stoneRoom->setExits(f, d, b, c);
    b->setExits(NULL, NULL, NULL, stoneRoom);
    c->setExits(NULL, NULL, stoneRoom, NULL);
    d->setExits(stoneRoom, NULL, e, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, stoneRoom, g, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, NULL, f, NULL);
    i->setExits(NULL, NULL, d, NULL);

    GameItem * roomBItems[] = {new Treasure};
    b->populateRoom(roomBItems,1);
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

Game::~Game()
{
    delete player;
    delete currentRoom;
    delete armoury;
    delete potions;
    delete keys;
    delete mediaPlayer;
    delete playlist;
    delete stoneRoom;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
    delete i;
}
