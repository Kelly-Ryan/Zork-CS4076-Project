#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <string>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QPixmap>

using std::string;

// GameItem is an abstract class

class GameItem:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    friend class Inventory;

private:
    float weight;
    string imgPath;
    void setWeight(float weight);
    void setDescription(string description);

protected:
     QString qtDescription;

public:
    GameItem (string description, float weight,string imgPath);
    GameItem(const GameItem &item); // must provide a copy constructor since the copy constructor in base class is marked as deleted
    GameItem();
    virtual void useItem() = 0;
    float getWeight();
    virtual QString itemInfo();
    string getImgPath();
    void setImgPath(string imgPath);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

signals:
    void itemSelected(GameItem *);
};

#endif // GAMEITEM_H
