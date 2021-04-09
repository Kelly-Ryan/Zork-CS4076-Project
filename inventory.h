#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <vector>
#include "gameitem.h"
#include "customlistwidget.h"
#include "gamePopup.h"
#include <QPushButton>
#include <QDebug>

using namespace Qt;

using std::vector;

template <typename T >class Inventory :public CustomListWidget
{

private:
    vector <T*> inventory;
    const int maxCapacity;
    int xPos;
    int yPos;
    string title;
    void onSelected(QListWidgetItem * widgetItem);
    void addToInventory(GameItem *itemCollected);
    void removeFromInventory();
    void moveEvent(QMoveEvent *event);
    T* convert(QListWidgetItem *widgetItem);

public:
    Inventory(string title,int maxCapacity = 5);
    int getMaxCapacity() const;
    void setPosition(int xPos, int yPos);
    string getTitle();
};

template<typename T> Inventory<T>::Inventory(string title,int maxCapacity):maxCapacity(maxCapacity)
{
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(onSelected(QListWidgetItem *)));
    setWindowTitle(QString::fromStdString(title)+ "\t Max Capacity:" + QString::number(maxCapacity));
    setWindowFlags(Tool | CustomizeWindowHint | WindowTitleHint | WindowStaysOnTopHint);
    setHorizontalScrollBarPolicy(ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(ScrollBarAlwaysOff);
    resize(240,150);
    show();
}

template<typename T> void Inventory<T>::setPosition(int xPos, int yPos)
{
    this->xPos = xPos;
    this->yPos = yPos;
    move(xPos,yPos);
}

template<typename T> int Inventory<T>::getMaxCapacity() const
{
    return maxCapacity;
}

template<typename T> string Inventory<T>::getTitle()
{
    return title;
}

template <typename T> void Inventory<T>::onSelected(QListWidgetItem *widgetItem)
{
    T *item;
    typename vector<T*>::iterator i;
    for (i = inventory.begin(); i != inventory.end(); i++)
    {
        if(widgetItem->text().startsWith((*i)->getDescription()))
        {
            item = (*i);
            break;
        }
    }
    GamePopup msg;
    msg.setText("Would you like to use this item or remove it from your inventory");
    QPushButton *use = msg.addButton("Use",QMessageBox::YesRole);
    msg.addButton("Remove",QMessageBox::RejectRole);
    msg.exec();
    if(msg.clickedButton() == use)
    {
        qDebug() << "Chosen to use the item";
        emit itemSelected(item);
    }
    else
    {
        inventory.erase(i);
        delete widgetItem;
        delete item;
    }
    delete use;
    emit restoreFocus();
}

template <typename T> void Inventory<T>::removeFromInventory()
{
    QListWidgetItem *widgetItem = currentItem();
    T *item;
    typename vector<T*>::iterator i;
    for (i = inventory.begin(); i != inventory.end(); i++)
    {
        if(widgetItem->text().startsWith((*i)->getDescription()))
        {
            item = (*i);
            break;
        }
    }
    inventory.erase(i);
    delete widgetItem;
    delete item;
}

template <typename T> void Inventory<T>::addToInventory(GameItem *itemCollected)
{
    T* item = dynamic_cast<T*>(itemCollected);

    if(inventory.size() < maxCapacity)
    {
        if(typeid(*itemCollected) == typeid(T)) //necessary so not added to both on screen
        {
            inventory.push_back(item);
            QListWidgetItem * inventoryItem = new QListWidgetItem(QIcon(QString::fromStdString(itemCollected->getImgPath())),itemCollected->itemInfo());
            addItem(inventoryItem);
            qDebug() << "Adding to inventory";
            emit itemAdded(itemCollected);
        }
    }
    else
    {
        GamePopup msg;
        msg.setText("This item cannot be added to the inventory. The inventory is at maximum capacity.");
        msg.exec();
    }
}

template <typename T> void Inventory<T>::moveEvent(QMoveEvent *event)
{
    move(xPos,yPos);
    emit restoreFocus();
}
#endif
