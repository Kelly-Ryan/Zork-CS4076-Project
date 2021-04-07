#include "enemy.h"
#include <cstdlib>
#include <cctype>
#include <time.h>
#include <QDebug>

Enemy::Enemy(string name,int damage,string imgPath)
{
    name[0] = toupper(name[0]);
    this->name = name;
    this->alive = true;
    this->damage = damage;
    srand(time(NULL));
    health = rand() % 3 + 3; // 3-5
    setPos(rand()%(700-300+1)+300,rand()%(500-100+1)+100);
    xIncrement = rand()%6; // 0-5
    yIncrement = rand()%6;
    timer = new QTimer();
    timer->start(80);
    connect(timer,SIGNAL(timeout()),this,SLOT(roam()));
    setPixmap(QPixmap(QString::fromStdString(imgPath)));
    lives = new Healthbar(name,health);
    lives->setPos(800,50);
}

Enemy::~Enemy()
{
    delete timer;
    delete lives;
}

void Enemy::roam()
{
    setPos(x()+xIncrement,y()+yIncrement);
    attackingPlayer();
    if(x() > 690 || x() < 310)  //550 50
        xIncrement *=-1;

    if(y() > 490 || y() < 110) // 450 40
        yIncrement *=-1;
}

int Enemy::getHealth()
{
    return health;
}

int Enemy::getDamage()
{
    return damage;
}

string Enemy::getName()
{
    return name;
}

bool Enemy::isAlive()
{
    return alive;
}

Healthbar* Enemy::getHealthbar()
{
    return lives;
}

void Enemy::attackingPlayer()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0;i < colliding_items.size(); i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
            qDebug() << "Enemy collided with player";
            Player *player = (Player *)colliding_items[i];
            if(typeid(*player->getItemHolding()) != typeid(Weapon))
            {
                qDebug() << "Attacking the player";
                qDebug() << player->getItemHolding()->getDescription();
                combat(this,player);
                player->getHealthbar()->updateHealth(player->getHealth());
            }
        }
    }
}

void operator+(Weapon &weapon,Enemy &enemy)
{
    enemy.health -= weapon.getDamage();
    if(enemy.health <= 0)
    {
        enemy.alive = false;
    }
}

