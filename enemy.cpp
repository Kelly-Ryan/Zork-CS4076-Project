#include "enemy.h"
#include "gamePopup.h"
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
    timer->start(200);
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
    collision();
    if(x() >= 700 || x() <= 300)  // room x coords are 300 - 700
        xIncrement *=-1;

    if(y() >= 500 || y() <= 100) // room y coords are 100 - 500
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

void Enemy::defeated()
{
    timer->stop();
    GamePopup congrats;
    congrats.setText("Congratulations you defeated the enemy");
    congrats.exec();
    delete this;
}

void Enemy::collision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0;i < colliding_items.size(); i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
             Player *player = (Player *)colliding_items[i];
             qDebug() << "Attacking the player";
             combat(this,player);
             if(player->isAlive())
                 player->getHealthbar()->updateHealth(player->getHealth());
//             setPos(x()+xIncrement*2,y()+yIncrement*2); // tbh its just a temp idea
             //QTimer::singleShot(100,this,SLOT(launchAttack())); soln is to make a subclassed timer with signal
        }
    }
}

void operator+(Weapon weapon,Enemy &enemy)
{
    enemy.health -= weapon.getDamage();
    if(enemy.health <= 0)
    {
        enemy.alive = false;
    }
}
