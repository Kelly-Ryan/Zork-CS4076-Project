#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <vector>
#include <QListWidget>
#include <QListWidgetItem>
#include "gameitem.h"
#include "item.h" //remove after

using std::vector;

class Inventory:public QListWidget{
    Q_OBJECT

private:
    vector <GameItem*> inventory;
    int currentCapacity = 0;
    const int maxCapacity;

private slots:
    void onSelected(QListWidgetItem * widgetItem);

public slots:
    void addToInventory(GameItem *item);

signals:
    void itemAdded(GameItem *item);
    void itemSelected(GameItem *item);

public:
    Inventory(int maxCapacity = 5);
    bool retrieveItem(GameItem *item); // remove after
    int getMaxCapacity() const;
};


#endif
