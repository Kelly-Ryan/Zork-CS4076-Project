#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <vector>
#include <QListWidget>
#include <QListWidgetItem>
#include "gameitem.h"

using std::vector;

template <typename T >class Inventory :public QListWidget{
    Q_OBJECT

private:
    vector <GameItem*> inventory;
    int currentCapacity = 0;
    const int maxCapacity;
    int xPos;
    int yPos;
    string title;

private slots:
    void onSelected(QListWidgetItem * widgetItem);

public slots:
    void addToInventory(GameItem *item);

/*signals:
    void itemAdded(GameItem *item);
    void itemSelected(GameItem *item);
    void restoreFocus();*/

public:
    Inventory(string title,int maxCapacity = 5);
    int getMaxCapacity() const;
    void moveEvent(QMoveEvent *event);
    void setPosition(int xPos, int yPos);
    string getTitle();
};


#endif
