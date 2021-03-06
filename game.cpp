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

    playlist->addMedia(QUrl("qrc:/sounds/sounds/Adventure Meme.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    mediaPlayer->setPlaylist(playlist);
    mediaPlayer->setAudioRole(QAudio::GameRole);
    mediaPlayer->play();

    createRooms();
    currentRoom = a;            //set current room/scene

    player = new Player(475, 275, this);  //position player in centre of room
    a->addItem(player);         //add player to scene
    a->addItem(player->getHealthbar());

    armoury = new Inventory<Weapon>("Armoury",3);
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

    armoury->setPosition(800,150);
    potions->setPosition(800,315);
    keys->setPosition(800,480);

    setScene(a);        //set first scene (room) in QGraphicsView
    show(); //show QGraphicsView
}

void Game::createRooms()
{
                        //room name, background image, isLocked
    a = new Room("Room A", QImage(":images/images/stoneRoom.png"), false);
    b = new Room("Room B", QImage(":images/images/stoneRoom.png"), true);
    c = new Room("Room C", QImage(":images/images/stoneRoom.png"), false);
    d = new Room("Room D", QImage(":images/images/stoneRoom.png"), false);
    e = new Room("Room E", QImage(":images/images/stoneRoom.png"), false);
    f = new Room("Room F", QImage(":images/images/stoneRoom.png"), false);
    g = new Room("Room G", QImage(":images/images/stoneRoom.png"), true);
    h = new Room("Room H", QImage(":images/images/stoneRoom.png"), true); 
    i = new Room("Room I", QImage(":images/images/stoneRoom.png"), false);

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

    GameItem * roomAItems[] = {new HealthPotion(":/images/images/2Lives.png",2),new Weapon("sword",2,":/images/images/sword.png")};
    a->populateRoom(roomAItems,2);
    Enemy *centaur = new Enemy("centaur",1,":/images/images/centaur.png");
    a->addItem(centaur);
    a->addItem(centaur->getHealthbar());

    GameItem * roomBItems[] = {new Treasure,new Weapon("Axe",3,":/images/images/axe.png"),new HealthPotion(":/images/images/2Lives.png",2)};
    b->populateRoom(roomBItems,3);
    Enemy *dragon = new Enemy("Dragon",4,":/images/images/dragon.png");
    b->addItem(dragon);
    b->addItem(dragon->getHealthbar());

    GameItem * roomCItems[] = {new HealthPotion(":/images/images/1Life .png",1)};
    c->populateRoom(roomCItems,1);

    Enemy *troll = new Enemy("Troll",2,":/images/images/troll.png");
    d->addItem(troll);
    d->addItem(troll->getHealthbar());

    GameItem * roomEItems[] = {new Weapon("Bow",1,":/images/images/bow.png"),new HealthPotion(":/images/images/3Lives.png",3), new RoomKey("Bronze Key",":images/images/bronze-key.png")};
    e->populateRoom(roomEItems,3);

    Enemy *giant = new Enemy("Giant",3,":/images/images/giant.png");
    f->addItem(giant);
    f->addItem(giant->getHealthbar());

    GameItem * roomGItems[] = {new HealthPotion(":/images/images/1Life.png",1), new RoomKey("Gold Key",":images/images/gold-key.png")};
    g->populateRoom(roomGItems,2);


    GameItem * roomHItems[] = {new Weapon("Axe",2,":/images/images/axe.png"), new RoomKey("Silver Key",":images/images/silver-key.png")};
    h->populateRoom(roomHItems,2);
    Enemy *cyclops = new Enemy("Cyclops",2,":/images/images/cyclops.png");
    h->addItem(cyclops);
    h->addItem(cyclops->getHealthbar());

    GameItem * roomIItems[] = {new HealthPotion(":/images/images/1Life .png",1)};
    i->populateRoom(roomIItems,1);
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
