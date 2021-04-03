#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QString>
#include <string>
#include <QGraphicsTextItem>

using std::string;

class Healthbar:public QGraphicsTextItem
{
private:
    QString entity;
    int health;
public:
    Healthbar(string entity,int health);
    void updateHealth(int currentHealth);
};

#endif // HEALTHBAR_H
