#include "Inventory.h"
#include <QDebug>
#include <QMessageBox>

Inventory::Inventory(float maxWeight):maxWeight(maxWeight){
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(onSelected(QListWidgetItem *)));
    setWindowTitle("Inventory");
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
}

void Inventory::addToInventory(GameItem *item) {
    if(currentWeight + item->weight <= maxWeight)
    {
        inventory.push_back(item);
        currentWeight += item->weight;
        QListWidgetItem * inventoryItem = new QListWidgetItem(QIcon(QString::fromStdString(item->imgPath)),item->itemInfo());
        addItem(inventoryItem);
        qDebug() << "Adding to inventory";
        emit itemCollected(item);
    }
    else
    {
        QMessageBox msg;
        msg.setText("This item cannot be added to the inventory. The invenotry is either at maximum capacity or there is insufficient space to add this item");
        msg.setWindowTitle("Insufficent space for item ");
        msg.exec();
    }
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

float Inventory::getMaxWeight() const
{
    return maxWeight;
}
