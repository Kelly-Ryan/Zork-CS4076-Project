


/*template<typename T>
void Inventory<T>::onSelected(QListWidgetItem *widgetItem)
{
    GameItem * item = inventory.front();
        for (vector<GameItem*>::iterator i = inventory.begin(); i != inventory.end(); i++)
        {
            if(widgetItem->text().startsWith((*i)->getDescription()))
            {
                item = (*i);
                break;
            }
        }

        GamePopup msg;
        msg.setText("Would you like to use this item or remove it from your inventory");
        msg.setInformativeText(item->howToUse());
        QPushButton *use = msg.addButton("Use",QMessageBox::YesRole);
        msg.addButton("Remove",QMessageBox::RejectRole);
        msg.move(350,300);
        msg.exec();
        if(msg.clickedButton() == use)
        {
            qDebug() << "Chosen to use the item";
//            emit itemSelected(item);
        }
        else
        {
            currentCapacity--;
            delete widgetItem;
            delete item;
        }
        delete use;
//        emit restoreFocus();
}

template<typename T>
void Inventory<T>::addToInventory(GameItem *item)
{
    if(currentCapacity < maxCapacity)
        {
            inventory.push_back(item);
            QListWidgetItem * inventoryItem = new QListWidgetItem(QIcon(QString::fromStdString(item->getImgPath())),item->itemInfo());
            addItem(inventoryItem);
            currentCapacity++;
            qDebug() << "Adding to inventory";
//            emit itemAdded(item);
        }
        else
        {
            GamePopup msg;
            msg.setText("This item cannot be added to the inventory. The inventory is at maximum capacity.");
            msg.exec();
        }
}

*/





