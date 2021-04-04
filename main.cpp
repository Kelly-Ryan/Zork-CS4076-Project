#include "game.h"
#include "mainwindow.h"

#include <QGraphicsView>
#include <QApplication>
#include <QMainWindow>
#include <QString>

string gameTitle = "Zork";

int main (int argc, char *argv[]){
    QApplication a(argc, argv);
    Game *game = new Game();                                        //create Game object
    MainWindow window;                                              //create window
    window.setWindowTitle(QString::fromStdString(gameTitle));
    window.setCentralWidget(game);                                  //set Game object in window
    window.show();                                                  //show window

    return a.exec();
}

// just me tryna figure out git :)
