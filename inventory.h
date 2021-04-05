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
    int xPos = 1375;
    int yPos = 650;

private slots:
    void onSelected(QListWidgetItem * widgetItem);

public slots:
    void addToInventory(GameItem *item);

signals:
    void itemAdded(GameItem *item);
    void itemSelected(GameItem *item);
    void restoreFocus();

public:
    Inventory(int maxCapacity = 5);
    bool retrieveItem(GameItem *item); // remove after
    int getMaxCapacity() const;
    void moveEvent(QMoveEvent *event);
};


#endif
