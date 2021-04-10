#include "gameitem.h"
#include <QMessageBox>
#include <QDebug>

GameItem::GameItem()
{
}

GameItem::GameItem (string description,string imgPath)
{
    setDescription(description);
    this->imgPath = imgPath;
    setPixmap(QPixmap(QString::fromStdString(imgPath)));
}

GameItem::GameItem(std::string description)
{
    setDescription(description);
}

GameItem::GameItem(const GameItem &item):QGraphicsPixmapItem()
{
    imgPath = item.imgPath;
    qtDescription = item.qtDescription;
}

void GameItem::setDescription(string description)
{
    this->qtDescription = QString::fromStdString(description);
}

QString GameItem::itemInfo()
{
    return qtDescription;
}

bool GameItem::isOutOfUse()
{
    return outOfUse;
}

void GameItem::setOutOfUse(bool outOfUse)
{
    this->outOfUse = outOfUse;
}

string GameItem::getImgPath()
{
    return imgPath;
}

void GameItem::setImgPath(string imgPath)
{
    this->imgPath = imgPath;
}

QString GameItem::getDescription()
{
    return qtDescription;
}
