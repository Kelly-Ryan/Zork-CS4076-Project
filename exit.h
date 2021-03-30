#ifndef EXIT_H
#define EXIT_H

#include <string>
using namespace std;

#include <QGraphicsPixmapItem>
#include <QObject>

class Exit : public QObject, public QGraphicsPixmapItem {
private:
    string direction;
public:
    Exit(QGraphicsItem * parent=0);
    Exit(string direction);
    string getDirection();
    ~Exit();
};

#endif // EXIT_H
