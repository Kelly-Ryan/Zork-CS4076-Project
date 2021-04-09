#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H

#include <QListWidget>
#include <QListWidgetItem>
#include "gameitem.h"

//This is an abstract class

class CustomListWidget:public QListWidget
{
   Q_OBJECT

public slots:
    virtual void addToInventory(GameItem *itemCollected) = 0;
    virtual void removeFromInventory() = 0;
    virtual void onSelected(QListWidgetItem *widgetItem) = 0;
    virtual void moveEvent(QMoveEvent *event) = 0;
signals:
    void itemAdded(GameItem *item);
    void itemSelected(GameItem *item);
    void restoreFocus();
};

#endif // CUSTOMLISTWIDGET_H
