#include "player.h"
#include "game.h"
#include "exit.h"
#include <QKeyEvent>

#include <string>
#include <iostream>

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

using namespace std;

Game::Game(QWidget *parent){
    //set size of QGraphicsView and remove scroll bars
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setFixedSize(1000,600);

    createRooms();
    currentRoom = a;            //set current room/scene

    player = new Player(500, 300);   //position player in centre of room
    a->addItem(player);         //add player to scene

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
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
}

void Game::printWelcome(){
    cout << "Welcome" << endl;
}

void Game::printHelp(){

}

Game::~Game(){

}


