#include "game.h"

#include <QGraphicsView>
#include <QApplication>

int main (int argc, char *argv[]){
    QApplication a(argc, argv);
    Game *game = new Game();          //create Game object
    game->show();               //show Game object

    return a.exec();
}
