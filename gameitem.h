#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <string>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QPixmap>

using std::string;

class GameItem:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    float weight;
    string imgPath;
    void setWeight(float weight);
    void setDescription(string description);

protected:
     QString qtDescription;

public:
    GameItem (string description, float weight,string imgPath);
    GameItem (string description);
    GameItem(const GameItem &item); // must provide a copy constructor since the copy constructor in base class is marked as deleted
    GameItem();
    float getWeight();
    virtual QString itemInfo();
    string getImgPath();
    void setImgPath(string imgPath);
    QString getDescription();

signals:
    void itemSelected(GameItem *);
};

#endif // GAMEITEM_H
