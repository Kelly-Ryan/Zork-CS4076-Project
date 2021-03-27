#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>



class Player : public QObject, public QGraphicsPixmapItem
{
private:
    void keyPressEvent(QKeyEvent *event);
public:
    Player(QGraphicsItem * parent=0);
};

#endif // PLAYER_H
