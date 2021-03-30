#include "Game.h"
#include <QDebug>
#include <QApplication>

string gameTitle = "ZORK";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game *game = new Game();
    game->show();

    return a.exec();
}


