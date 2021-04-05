#include "game.h"
#include "mainwindow.h"

#include <QGraphicsView>
#include <QApplication>
#include <QMainWindow>
#include <QString>

QString gameTitle = "Zork";

int main (int argc, char *argv[]){
    QApplication a(argc, argv);
    Game *game = new Game();                                        //create Game object
    MainWindow window;                                              //create window
    window.setWindowTitle(::gameTitle);
    window.setCentralWidget(game);                                  //set Game object in window
    window.setWindowFlags(Qt::WindowCloseButtonHint);
    window.show();                                                  //show window

    return a.exec();
}
