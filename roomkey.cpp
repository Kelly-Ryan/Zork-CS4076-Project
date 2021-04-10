#include "roomkey.h"

RoomKey::RoomKey():GameItem("Key")
{
    setPixmap(QPixmap(":/images/images/key.png"));
    setImgPath(":/images/images/key.png");
}

QString RoomKey::itemInfo()
{
    return qtDescription;
}
