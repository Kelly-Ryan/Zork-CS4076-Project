#include "Enemy.h"
#include <cstdlib>
#include <time.h>

Enemy::Enemy(string name,string imgPath)
{
    this->name = name;
    this->alive = true;
    srand(time(NULL));
    health = rand() % 3 + 3; // 3-5
    setPos(rand()%1000,rand()%600);
    xIncrement = rand()%10; // 0-9
    yIncrement = rand()%10;
    timer = new QTimer();
    timer->start(40);
    connect(timer,SIGNAL(timeout()),this,SLOT(roam()));
    setPixmap(QPixmap(QString::fromStdString(imgPath)));
}

Enemy::~Enemy()
{
    delete timer;
}

void Enemy::roam()
{
    setPos(x()+xIncrement,y()+yIncrement);
    if(x() > 900 || x() < 100)
        xIncrement *=-1;
    if(y() > 500 || y() < 100)
        yIncrement *=-1;
}

int Enemy::getHealth()
{
    return health;
}

string Enemy::getName()
{
    return name;
}

bool Enemy::isAlive()
{
    return alive;
}

void operator+(Enemy &enemy,Weapon &weapon)
{
    enemy.health -= weapon.getDamage();
    if(enemy.health <= 0)
    {
        enemy.alive = false;
    }
}
