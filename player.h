#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player : public QObject, public QGraphicsPixmapItem {
private:
    void keyPressEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent *event1, QKeyEvent *event2);
    double speed, diagSpeed;
public:
    Player(QGraphicsItem * parent=0);
    ~Player();
};

#endif // PLAYER_H
