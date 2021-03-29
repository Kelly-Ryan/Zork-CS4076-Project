#include "player.h"
#include "game.h"
#include "exit.h"
#include <QKeyEvent>

#include <string>
#include <iostream>
using namespace std;

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

Game::Game(QWidget *parent){
    //set size of QGraphicsView and remove scroll bars
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setFixedSize(1000,600);

    //room 1 scene
    QGraphicsScene *room1scene = new QGraphicsScene();
    room1scene = new QGraphicsScene();
    room1scene->setSceneRect(0,0,1000,600);           //set scene dimensions
    room1scene->setBackgroundBrush(QBrush(QImage(":/images/images/room1.png")));
    Exit *exit = new Exit();
    exit->setExitImage("north");
    exit->setPos(450, 0);
    room1scene->addItem(exit);

    //room 2 scene
    QGraphicsScene *room2scene = new QGraphicsScene();
    room2scene = new QGraphicsScene();
    room2scene->setSceneRect(0,0,1000,600);           //set scene dimensions
    room2scene->setBackgroundBrush(QBrush(QImage(":/images/images/room2.png")));

    //add player
    Player *player = new Player();
    room1scene->addItem(player);                        //add player item to scene

    //set QGraphicsScene in QGraphicsView
    setScene(room1scene);

    show(); //show scene in QGraphicsView
    //scenecontroller.createRoomScenes()
    //scenecontroller.setRoom(string room)
}

void Game::go(string direction) {
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){
        ;
    }else{
        currentRoom = nextRoom;
        //load scene for currentRoom
    }
}

void Game::changeRoom(QGraphicsScene *room) {
    //load the room and scene
    setScene(room);
}

void Game::printWelcome(){
    cout << "Welcome" << endl;
}

void Game::printHelp(){

}

Game::~Game(){
    delete room1scene;
    delete room2scene;
}


