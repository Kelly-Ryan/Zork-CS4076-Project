#include "roomkey.h"

RoomKey::RoomKey(string description, string imgPath):GameItem()
{
    this->qtDescription = QString::fromStdString(description);
    setPixmap(QPixmap(QString::fromStdString(imgPath)));
    setImgPath(imgPath);
}


QString RoomKey::itemInfo()
{
    return qtDescription;
}
