#ifndef WEAPON_H
#define WEAPON_H

#include "gameitem.h"
#include "enemy.h"
#include <QDebug>

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

class Weapon : public GameItem
{
private:
    int *damage;

public:
    Weapon();
    ~Weapon();
    Weapon(string description, int destruction, string imgPath);
    Weapon(const Weapon &weapon);
    virtual QString itemInfo();
    int getDamage();
};

#endif // WEAPON_H


