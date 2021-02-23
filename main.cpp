#include "mainwindow.h"

#include <QApplication>
#include <QMediaPlaylist>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QMediaPlaylist* playlist = new QMediaPlaylist(); //how to deal with this memory leak??
    playlist -> addMedia(QUrl("qrc:/sounds/sound.mp3"));
    playlist -> setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer* player = new QMediaPlayer();
    player -> setPlaylist(playlist);
    player -> play();
    return a.exec();
}
