#include "Item.h"
#include <QDebug>
#include <QMessageBox>
/*Item::Item (string description, float weight, int usuageLimit)
{
    this->usuageLimit = usuageLimit;
    setDescription(description);
    setWeight(weight);
}*/
Item::Item()
{
}

int Item::usesRemaining()
{
    return usuageLimit - uses;
}

Item::Item (string description,float weight, int usuageLimit,string imgPath)
{
    this->usuageLimit = usuageLimit;
    this->qtDescription = QString::fromStdString(description);
    setDescription(description);
    setWeight(weight);
    this->imgPath = imgPath;
    setPixmap(QPixmap(QString::fromStdString(imgPath)));

}

Item::Item(const Item &item):QObject(),QGraphicsPixmapItem()
{
   qtDescription = item.qtDescription;
   description = item.description;
   weight = item.weight;
   usuageLimit = item.usuageLimit;
   uses = item.uses;
   imgPath = item.imgPath;
}

void Item::setWeight(int weight)
{
    if (weight > 9999 || weight < 0)
       //cout << "weight invalid, must be 0<weight<9999" ; user defined exception below is only temporary
        this->weight = 100;
    else
        this->weight = weight;
}

int Item::getUsuageLimit()
{
    return usuageLimit;
}

int Item::getWeight()
{
    return weight;
}

string Item::getDescription()
{
    return description;
}

void Item::setDescription(string description)
{
    this->description = description;
}

int Item::numberOfUses()
{
    return uses;
}

int operator+(Item &item1,Item &item2)
{
    return item1.weight + item2.weight;
}

Item Item::operator++(int)
{
    Item item;
    item.uses = uses++;
    return item;
}

int Item::operator==(Item item)
{
    return !this->description.compare(item.getDescription()); // need to use ! as the compare method returns 0 when 2 strings are the same
}

/*Item & Item::operator=(const Item &item)
{
    description = item.description;
    weight = item.weight;
    usuageLimit = item.usuageLimit;
    uses = item.uses;
    imgPath = item.imgPath;
    return *this;
}*/


QString Item::itemInfo()
{

    return QString::fromStdString(description + "\tRemaining Uses:") + QString::number(usesRemaining());
}

string Item::getImgPath()
{
    return imgPath;
}

void Item::setImgPath(string imgPath)
{
    this->imgPath = imgPath;
}

void Item::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Attempting to pick up item";
    QMessageBox msg;
    msg.setWindowTitle("Item information");
    msg.setText("Do you want to add " + qtDescription + " to the inventory?");
    msg.setInformativeText("This item has a maximum of " + QString::number(usuageLimit) + " uses and a weight of " + QString::number(weight));
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg.setDefaultButton(QMessageBox::Yes);
    int response = msg.exec();

    if(response == QMessageBox::Yes) emit itemSelected(this);
}
