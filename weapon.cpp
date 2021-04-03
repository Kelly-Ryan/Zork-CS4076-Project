#include "weapon.h"
#include <QtDebug>

Weapon::Weapon()
{
}

Weapon::Weapon(string description, float weight, int damage,string imgPath):GameItem(description,weight,imgPath)
{
    this->damage = damage;
}

void Weapon::useItem()
{
    qDebug() << "Attacking with weapon";
}

QString Weapon::itemInfo()
{
    return qtDescription + QString::fromStdString("\tDamage Inflicted:") + QString::number(damage);
}

int Weapon::getDamage()
{
    return damage;
}

