#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include <QApplication>
#include <QMessageBox>

MainWindow::MainWindow(){
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    createActions();
    createMenus();
}

void MainWindow::about(){
    QMessageBox::about(this, "About This Game","Zork was originally published in 1979 as a text adventure game. "
    "This game is a short Zork-inspired dungeon crawler written by Clodagh Walsh and Kelly Ryan  in "
    "2021 using C++ and Qt.");
}

void MainWindow::quit(){
    exit(0);
}

void MainWindow::instructions(){
    QMessageBox::about(this, "How to Play","Up = W\nDown = S\nLeft = A\nRight = D\nAttack = Spacebar\n"
    "Pick-up Item = WSAD to approach it\nUse Item = Double-Click");
}

void MainWindow::createActions(){
    instructionsAct = new QAction("&How to Play", this);
    connect(instructionsAct, SIGNAL(triggered()), this, SLOT(instructions()));

     aboutAct = new QAction(tr("&About the Game"), this);
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction("&About Qt", this);
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

     quitAct = new QAction("&Quit Game", this);
     connect(quitAct, SIGNAL(triggered()), this, SLOT(quit()));
}

void MainWindow::createMenus(){
    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(instructionsAct);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    helpMenu = menuBar()->addMenu("&Quit");
    helpMenu->addAction(quitAct);
}

MainWindow::~MainWindow(){

}
