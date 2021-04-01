#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include "Weapon.h"

using std::string;

class Enemy: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    friend void operator+(Enemy &enemy,Weapon &weapon);

private:
    int health;
    bool alive;
    int xIncrement;
    int yIncrement;
    string name;
    QTimer *timer;

private slots:
    void roam();

public:
    Enemy();
    ~Enemy();
    Enemy(string name,string imgPath);
    int getHealth();
    string getName();
    bool isAlive();
};

#endif // ENEMY_H
