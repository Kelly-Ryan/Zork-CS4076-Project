#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <string>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QPixmap>

using std::string;

class GameItem:public QGraphicsPixmapItem
{
    template<typename T> friend class Inventory;
private:
    string imgPath;
    bool outOfUse = false;
    void setDescription(string description);

protected:
    QString qtDescription;

public:
    GameItem(string description,string imgPath);
    GameItem(string description);
    GameItem(const GameItem &item); // must provide a copy constructor since the copy constructor in base class is marked as deleted
    GameItem();
    virtual QString itemInfo();
    bool isOutOfUse();
    void setOutOfUse(bool outOfUse);
    string getImgPath();
    void setImgPath(string imgPath);
    QString getDescription();
};

#endif // GAMEITEM_H
