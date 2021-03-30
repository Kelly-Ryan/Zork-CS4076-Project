#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player : public QObject, public QGraphicsPixmapItem {
private:
    void keyPressEvent(QKeyEvent *event);
    bool exitCollision();
    int speed;
public:
    Player(QGraphicsItem * parent=0);
    Player(int xPos, int yPos);
    ~Player();
};

#endif // PLAYER_H
