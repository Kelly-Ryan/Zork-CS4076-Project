#include "roomkey.h"

namespace String{
   QString toString(string s){
        return QString::fromStdString(s);
    }
}

using namespace String;

RoomKey::RoomKey(string description, string imgPath):GameItem()
{
    this->qtDescription = toString(description);
    setPixmap(QPixmap(toString(imgPath)));
    setImgPath(imgPath);
}

QString RoomKey::itemInfo()
{
    return qtDescription;
}

