#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMainWindow>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

#include "player.h"
#include "enemy.h"
#include "room.h"
#include "inventory.h"
#include "gameitem.h"
#include "weapon.h"
#include "healthpotion.h"
#include "treasure.h"
#include "roomkey.h"

namespace Zork{
   QString toQString(string s){
        return QString::fromStdString(s);
   }

   string capitalise(string s){
       s[0] = toupper(s[0]);
       return s;
   }

   template<class T1,class T2> void combat(T1 attacker,T2 attackee)
   {
      qDebug() << attackee->getHealth();
      qDebug() << attacker->getDamage();
      *attacker + *attackee;
      qDebug() << attackee->getHealth();
      if(!attackee->isAlive())
      {
          qDebug() << "defeated";
          attackee->getHealthbar()->updateHealth(0);
          attackee->defeated();
      }
   }
}


class Player;
class Enemy;
class Weapon;

//QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene.
class Game : public QGraphicsView  {
    Q_OBJECT
private:
    Room *stoneRoom, *b, *c, *d, *e, *f, *g, *h, *i;
    Inventory<Weapon> *armoury;
    Inventory<HealthPotion> *potions;
    Inventory<RoomKey> *keys;
    QMediaPlaylist* playlist = new QMediaPlaylist();
    QMediaPlayer* mediaPlayer = new QMediaPlayer();
    void createRooms();
    void printWelcome();
    void help();
private slots:
    void removeFromRoom(GameItem *item);
    void enableMovement();
public:
    Player *player;
    Room *currentRoom;
    Game(QWidget *parent = nullptr);
    ~Game();
};

#endif // GAME_H
