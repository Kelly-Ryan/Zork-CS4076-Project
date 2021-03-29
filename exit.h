#ifndef EXIT_H
#define EXIT_H

#include <string>
using namespace std;

#include <QGraphicsPixmapItem>
#include <QObject>


class Exit : public QObject, public QGraphicsPixmapItem {
public:
    Exit(QGraphicsItem * parent=0);
    Exit(string *dir);
    void setExitImage(string *dir);
    ~Exit();
};

#endif // EXIT_H
