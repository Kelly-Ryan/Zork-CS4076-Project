#include "inventory.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>

using namespace Qt;

Inventory::Inventory(int maxCapacity):maxCapacity(maxCapacity){
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(onSelected(QListWidgetItem *)));
    setWindowTitle("Inventory \tMax Capacity:" + QString::number(maxCapacity));
//    setWindowFlags(Qt::Tool | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
    setWindowFlags(Tool | CustomizeWindowHint | WindowTitleHint | WindowStaysOnTopHint);
    move(xPos,yPos);
}

void Inventory::moveEvent(QMoveEvent *event)
{
    move(xPos,yPos);
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
        msg.setText("This item cannot be added to the inventory. The inventory is at maximum capacity.");
//        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setWindowFlags(FramelessWindowHint);
        msg.setStyleSheet("background-color:gray;border-style:outset");
        msg.move(350,300);
        msg.exec();
    }    
}

void Inventory::onSelected(QListWidgetItem *widgetItem)
{
    GameItem * item = inventory.front();
    for (vector<GameItem*>::iterator i = inventory.begin(); i != inventory.end(); i++)
    {
        if(widgetItem->text().startsWith((*i)->qtDescription))
        {
            item = (*i);
            break;
        }
    }

    QMessageBox msg;
    msg.setText("Would you like to use this item or remove it from your inventory");
    msg.setInformativeText(item->howToUse());
//    msg.setWindowFlags(Qt::FramelessWindowHint);
    msg.setWindowFlags(FramelessWindowHint);
    msg.setStyleSheet("background-color:gray;border-style:outset");
    QPushButton *use = msg.addButton("Use",QMessageBox::YesRole);
    msg.addButton("Remove",QMessageBox::RejectRole);
    msg.move(350,300);
    msg.exec();
    if(msg.clickedButton() == use)
    {
        qDebug() << "Chosen to use the item";
        emit itemSelected(item);
    }
    else
    {
        delete widgetItem;
        delete item;
    }
    delete use;
    emit restoreFocus();
}

// dont think this is needed
/*bool Inventory::retrieveItem(GameItem *item)
{
    if(item->uses < item->usuageLimit)
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

     return false;
    item->useItem();
    return true;
}*/

int Inventory::getMaxCapacity() const
{
    return maxCapacity;
}
