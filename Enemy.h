#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

using std::string;

class Enemy: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int health;
    bool alive;
    int xIncrement;
    int yIncrement;
    string name;
    QTimer *timer;

private slots:
    void roam();

public:
    Enemy();
    ~Enemy();
    Enemy(string name,string imgPath);
    int getHealth();
    string getName();
    bool isAlive();
};

#endif // ENEMY_H
