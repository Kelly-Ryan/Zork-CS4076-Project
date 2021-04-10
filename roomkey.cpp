#include "roomkey.h"

RoomKey::RoomKey(string description, string imgPath):GameItem()
{
    this->description = description;
    setPixmap(QPixmap(QString::fromStdString(imgPath)));
    //setImgPath(":/images/images/key.png");
}


QString RoomKey::itemInfo()
{
    return qtDescription;
}
