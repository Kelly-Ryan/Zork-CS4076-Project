#include "game.h"

#include <QGraphicsView>
#include <QApplication>

string gameTitle = "Zork";

int main (int argc, char *argv[]){
    QApplication a(argc, argv);
    Game *game = new Game();          //create Game object
    game->show();               //show Game object

    return a.exec();
}

// just me tryna figure out git :)
