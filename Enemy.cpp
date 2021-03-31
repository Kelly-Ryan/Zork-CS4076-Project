#include "Enemy.h"
#include <cstdlib>
#include <time.h>

Enemy::Enemy(string name,string imgPath)
{
    this->name = name;
    this->alive = true;
    srand(time(NULL));
    health = rand() % 3 + 3; // 3-5
    setPos(rand()%1920,rand()%1080);
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
    if(x() > 1820 || x() < 100)
        xIncrement *=-1;
    if(y() > 980 || y() < 100)
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
