#ifndef WEAPON_H
#define WEAPON_H

#include "gameitem.h"
#include <QDebug>

template<class T1,class T2> void combat(T1 attacker,T2 attackee)
{
   qDebug() << attackee->getHealth();
   qDebug() << attacker->getDamage();
   attackee->takeDamage(attacker->getDamage());
   qDebug() << attackee->getHealth();
   // perhaps do attackee.isAlive and if not emit a signal
}

class Weapon : public GameItem
{
private:
    int damage;

public:
    Weapon();
    Weapon(string description, float weight, int damage, string imgPath);
    void useItem();
    virtual QString itemInfo();
    int getDamage();
};

#endif // WEAPON_H


