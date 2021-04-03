#include "inventory.h"
#include <QDebug>
#include <QMessageBox>

Inventory::Inventory(int maxCapacity):maxCapacity(maxCapacity){
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(onSelected(QListWidgetItem *)));
    setWindowTitle("Inventory \tMax Capacity:" + QString::number(maxCapacity));
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
}

void Inventory::addToInventory(GameItem *item) {
    if(currentCapacity < maxCapacity)
    {
        inventory.push_back(item);
        QListWidgetItem * inventoryItem = new QListWidgetItem(QIcon(QString::fromStdString(item->imgPath)),item->itemInfo());
        addItem(inventoryItem);
        currentCapacity++;
        qDebug() << "Adding to inventory";
        emit itemAdded(item);
    }
    else
    {
        QMessageBox msg;
        msg.setText("This item cannot be added to the inventory. The inventory is either at maximum capacity or there is insufficient space to add this item");
        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setStyleSheet("background-color:gray;border-style:outset");
        msg.exec();
    }
    clearFocus();
}

void Inventory::onSelected(QListWidgetItem *widgetItem)
{
    qDebug() << "Attepting to use item";
    GameItem * itemToUse = inventory.front();
    for (vector<GameItem*>::iterator i = inventory.begin(); i != inventory.end(); i++)
    {
        if(widgetItem->text().startsWith((*i)->qtDescription))
        {
            itemToUse = (*i);
            break;
        }
    }
    itemToUse->useItem();
    clearFocus();
    //retrieveItem(itemToUse);
    /*if(retrieveItem(itemToUse))
    {
        widgetItem->setText(itemToUse->itemInfo());
    }
    else
    {
        delete widgetItem;
    }*/
}

bool Inventory::retrieveItem(GameItem *item)
{
    /*if(item->uses < item->usuageLimit)
    {
          qDebug() << "Using item " << item->qtDescription ;
          Item &temp = *item; // making a reference to item * as cant directly use ++ operator on pointer
          temp++;
          if(item->usesRemaining() == 0)
          {
             qDebug() << "Items last use will now be deleted";
             QMessageBox msg;
             msg.setText("This item has reached its's maximum usuage it will now be removed from your inventory");
             msg.setWindowTitle("Item has reached its max usuage");
             msg.exec();
             delete item;
             return false;
          }
          return true;
     }

     return false;*/
    item->useItem();
    return true;
}

int Inventory::getMaxCapacity() const
{
    return maxCapacity;
}
