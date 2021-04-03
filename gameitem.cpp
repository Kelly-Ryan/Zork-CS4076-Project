#include "gameitem.h"
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

QString GameItem::getDescription()
{
    return qtDescription;
}
