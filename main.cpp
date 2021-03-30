#include "game.h"

#include <QGraphicsView>
#include <QApplication>

Game *game; //global game object

int main (int argc, char *argv[]){
    QApplication a(argc, argv);
    game = new Game();          //create Game object
    game->show();               //show Game object

    return a.exec();
}
