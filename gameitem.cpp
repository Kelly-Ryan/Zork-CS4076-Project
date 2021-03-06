#include "gameitem.h"
#include "zorknamespace.h"// must include to use custom namespace
#include <QMessageBox>
#include <QDebug>

using namespace Zork;

GameItem::GameItem()
{
}

GameItem::GameItem (string description,string imgPath)
{
    setDescription(description);
    this->imgPath = imgPath;
    setPixmap(QPixmap(Zork::toQString(imgPath)));
}

GameItem::GameItem(std::string description)
{
    setDescription(description);
}

GameItem::GameItem(const GameItem &item):QGraphicsPixmapItem()
{
    qDebug() << "copy constructor of gameitem";
    imgPath = item.imgPath;
    qtDescription = item.qtDescription;
}

void GameItem::setDescription(string description)
{
   this->qtDescription = toQString(capitalise(description));
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
