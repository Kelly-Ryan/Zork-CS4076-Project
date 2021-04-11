#include "healthbar.h"
#include "zorknamespace.h"
#include <QFont>

using namespace Zork;

Healthbar::Healthbar(string entity, int health)
{
    this->entity = toQString(capitalise(entity));
    this->health = health;
    setDefaultTextColor(Qt::white);
    setFont(QFont("Adventure", 12));
    setPlainText(this->entity + QString("'s Health:") + QString::number(health));
}

void Healthbar::updateHealth(int currentHealth)
{
    health = currentHealth;
    setPlainText(entity + QString("'s Health:") + QString::number(health));
}
