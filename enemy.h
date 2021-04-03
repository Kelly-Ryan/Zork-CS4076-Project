#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include "weapon.h"
#include "player.h"

using std::string;

class Enemy: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    friend void operator+(Enemy &enemy,Weapon &weapon);

private:
    int health;
    int damage;
    bool alive;
    int xIncrement;
    int yIncrement;
    string name;
    QTimer *timer;
    void attackingPlayer();

private slots:
    void roam();

public:
    Enemy();
    ~Enemy();
    Enemy(string name,int damage,string imgPath);
    int getHealth();
    string getName();
    bool isAlive();
};

#endif // ENEMY_H
