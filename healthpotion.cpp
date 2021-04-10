#include "healthpotion.h"

HealthPotion::HealthPotion(string imgPath, int bonus):GameItem("Health Potion",imgPath)
{
    this->bonus = bonus;
}

QString HealthPotion::itemInfo()
{
    return qtDescription + QString::fromStdString(" Bonus:") + QString::number(bonus);
}

int HealthPotion::getBonus()
{
    return bonus;
}
