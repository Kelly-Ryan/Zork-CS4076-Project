#include "weapon.h"
#include <QtDebug>

Weapon::Weapon()
{
}


Weapon::~Weapon()
{
    delete d;
}

Weapon::Weapon(string description, int damage,string imgPath):GameItem(description,imgPath)
{
    d = new int;
    *d = damage;
}

Weapon::Weapon(const Weapon &weapon):GameItem(weapon)
{
    d = new int;
    *d = *(weapon.d);
}

QString Weapon::itemInfo()
{
    return qtDescription + QString::fromStdString("\tDamage:") + QString::number(getDamage());
}

int Weapon::getDamage()
{
    return *d;
}

