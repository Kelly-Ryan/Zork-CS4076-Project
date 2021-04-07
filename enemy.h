#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include "weapon.h"
#include "player.h"
#include "healthbar.h"

using std::string;
class Weapon;

class Enemy: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    friend void operator+(Weapon weapon,Enemy &enemy);

private:
    int health;
    int damage;
    bool alive;
    int xIncrement;
    int yIncrement;
    string name;
    QTimer *timer;
    Healthbar *lives;
    void collision();

private slots:
    void roam();
    void launchAttack();

public:
    Enemy();
    ~Enemy();
    Enemy(string name,int damage,string imgPath);
    int getHealth();
    string getName();
    bool isAlive();
    int getDamage();
    Healthbar* getHealthbar();
};

#endif // ENEMY_H
