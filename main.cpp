#include "Game.h"

#include <QGraphicsView>
#include <QApplication>

Game *game; //global game object
string gameTitle = "Zork";

int main (int argc, char *argv[]){
    QApplication a(argc, argv);
    game = new Game();          //create Game object
    game->show();               //show Game object

    return a.exec();
}
