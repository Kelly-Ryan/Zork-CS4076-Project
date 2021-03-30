#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <string>
#include <vector>
#include <QListWidget>
#include <QListWidgetItem>
#include "Item.h"

using std::vector;

class Inventory:public QListWidget{
    Q_OBJECT

private:
    vector <Item*> inventory;
    int currentWeight = 0;
    const int maxWeight;

private slots:
    void onSelected(QListWidgetItem * widgetItem);

public slots:
    void addToInventory(Item *item);

public:
    Inventory(int maxWeight = 500);
    bool useItem(Item *item);

    //void removeItem(Item )
//    need other inventory methods like search for item in inventory and delete from it
//    vector<Item*> getInventory();
    //string inventoryContents();

    int getMaxWeight() const;
};


#endif
