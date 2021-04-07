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
       attackee->hide();
   }
   // use overloaded + instead and then do the isAlive check so a proper fn
   // perhaps do attackee.isAlive and if not emit a signal
}

class Weapon : public GameItem
{
private:
    int *d;

public:
    Weapon();
    ~Weapon();
    Weapon(string description, float weight, int damage, string imgPath);
    Weapon(string description, int damage);
    Weapon(const Weapon &weapon);
    QString howToUse();
    virtual QString itemInfo();
    int getDamage();
};

#endif // WEAPON_H


