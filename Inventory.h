#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <vector>
#include <QListWidget>
#include <QListWidgetItem>
#include "GameItem.h"

using std::vector;

class Inventory:public QListWidget{
    Q_OBJECT

private:
    vector <GameItem*> inventory;
    float currentWeight = 0;
    const float maxWeight;

private slots:
    void onSelected(QListWidgetItem * widgetItem);

public slots:
    void addToInventory(GameItem *item);

signals:
    void itemCollected(GameItem *item);

public:
    Inventory(float maxWeight = 500);
    bool retrieveItem(GameItem *item);
    float getMaxWeight() const;
};


#endif
