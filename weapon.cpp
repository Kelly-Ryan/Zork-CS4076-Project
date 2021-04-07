#include "weapon.h"
#include <QtDebug>

Weapon::Weapon()
{
}

Weapon::Weapon(string description, float weight, int damage,string imgPath):GameItem(description,weight,imgPath)
{
    this->damage = damage;
}

Weapon::Weapon(string description, int damage):GameItem(description)
{
    this->damage = damage;
}

QString Weapon::howToUse()
{
    return "Attack any enemies using this weapon";
}

QString Weapon::itemInfo()
{
    return qtDescription + QString::fromStdString("\tDamage Inflicted:") + QString::number(damage);
}

int Weapon::getDamage()
{
    return damage;
}

