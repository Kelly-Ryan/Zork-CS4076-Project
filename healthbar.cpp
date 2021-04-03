#include "healthbar.h"
#include <QFont>
Healthbar::Healthbar(string entity, int health)
{
    this->entity = QString::fromStdString(entity);
    this->health = health;
    setDefaultTextColor(Qt::white);
    setFont(QFont("Adventure", 15));
    setPlainText(this->entity + QString("'s Health:") + QString::number(health));
}

void Healthbar::updateHealth(int currentHealth)
{
    health = currentHealth;
    setPlainText(entity + QString("'s Health:") + QString::number(health));
}
