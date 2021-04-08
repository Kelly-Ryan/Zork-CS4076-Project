#include "item.h"
#include <QDebug>
#include <QMessageBox>

Item::Item():usuageLimit(1)
{
}

Item::Item (string description, float weight, int usuageLimit, string imgPath):GameItem(description,weight,imgPath),usuageLimit(usuageLimit)
{
}

int Item::usesRemaining()
{
    return usuageLimit - uses;
}

int Item::getUsuageLimit() const
{
    return usuageLimit;
}

int Item::numberOfUses()
{
    return uses;
}

QString Item::itemInfo()
{
    return qtDescription + QString::fromStdString("\tRemaining Uses:") + QString::number(usesRemaining());
}


