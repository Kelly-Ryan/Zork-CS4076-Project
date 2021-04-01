#include "GameItem.h"
#include <QMessageBox>
#include <QDebug>

GameItem::GameItem()
{
}

GameItem::GameItem (string description,float weight,string imgPath)
{
    setDescription(description);
    setWeight(weight);
    this->imgPath = imgPath;
    setPixmap(QPixmap(QString::fromStdString(imgPath)));
}

void GameItem::setWeight(float weight)
{
    if (weight > 9999 || weight < 0)
       //cout << "weight invalid, must be 0<weight<9999" ; user defined exception below is only temporary
        this->weight = 100;
    else
        this->weight = weight;
}

float GameItem::getWeight()
{
    return weight;
}

void GameItem::setDescription(string description)
{
    this->qtDescription = QString::fromStdString(description);
}

QString GameItem::itemInfo()
{

    return qtDescription;
}

string GameItem::getImgPath()
{
    return imgPath;
}

void GameItem::setImgPath(string imgPath)
{
    this->imgPath = imgPath;
}

void GameItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Attempting to pick up item";
    QMessageBox msg;
    msg.setWindowTitle("Item information");
    msg.setText("Do you want to add " + qtDescription + " to the inventory?");
//    msg.setInformativeText("This item has a maximum of " + QString::number(usuageLimit) + " uses and a weight of " + QString::number(weight));
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg.setDefaultButton(QMessageBox::Yes);
    msg.setWindowFlags(Qt::FramelessWindowHint);
    msg.setStyleSheet("background-color:gray;border-style:outset");
    int response = msg.exec();

    if(response == QMessageBox::Yes) emit itemSelected(this);
}
