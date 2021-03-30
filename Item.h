#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>

using std::string;

class Item:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    friend class Inventory;
    friend int operator+(Item &item1,Item &item2);// dont know if this is gonna be any good

private:
    string description; //dont even think need this
    QString qtDescription;
    float weight;
    int usuageLimit;
    int uses = 0;
    string imgPath;
    int usesRemaining();

signals:
    void itemSelected(Item *);

public:
    // coul add default arguments perhaps
//    Item (string description, float weight, int usuageLimit);
    Item (string description, float weight, int usuageLimit, string imgPath);
    Item(const Item &item); // must provide a copy constructor since the copy constructor in base class is marked as deleted
    Item();
    string getDescription();
    void setDescription(string description);
    int getWeight();
    void setWeight(int weightGrams);
    int getUsuageLimit();
    int numberOfUses();
    Item operator++(int);
    int operator==(Item item); //dunno if need anymore
//    Item & operator=(const Item &item);
    QString itemInfo();
    string getImgPath();
    void setImgPath(string imgPath);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
};


#endif /*ITEM_H_*/
