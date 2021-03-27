#include "player.h"
#include "game.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

Game::Game(QWidget *parent){
    //set size of QGraphicsView and remove scroll bars
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setFixedSize(800,600);

    //create room 1
    QGraphicsScene *room1scene = new QGraphicsScene();
    room1scene->setSceneRect(0,0,800,600);           //set scene dimensions
    room1scene->setBackgroundBrush(QBrush(QImage(":/images/images/room1bg.png")));

    //set QGraphicsScene in QGraphicsView
    setScene(room1scene);

    //add player
    Player *player = new Player();
    player->setPos(400,300);                            //set position of player
    player->setFlag(QGraphicsItem::ItemIsFocusable);    //make player focusable
    player->setFocus();                                 //set focus on player
    room1scene->addItem(player);                        //add player item to scene

    show(); //show scene in QGraphicsView
}

void Game::createRooms(){
    Room *room1, *room2;

    room1 = new Room("Room 1", QImage(":/images/images/room1bg.png"));
    room2 = new Room("Room 2", QImage(":/images/room2bg.png"));

                     //North, South, East, West
    room1->setExits(room2, NULL, NULL, NULL);
    room2->setExits(NULL, room1, NULL, NULL);

    //starting area
    currentRoom = room1;
    //load scene for currentRoom
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


void Game::printWelcome(){
    cout << "Welcome" << endl;
}

void Game::printHelp(){

}


