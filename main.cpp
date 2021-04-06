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
    window.move(0,0);                                               //display window at top 0,0 so that screen size is not an issue
    window.show();                                                  //show window

    return a.exec();
}
