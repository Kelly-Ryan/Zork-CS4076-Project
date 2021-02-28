#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui ->setupUi(this);
    QListWidgetItem *money = new QListWidgetItem(QIcon(":/images/money.jfif"),"Cash");
    QListWidgetItem *phone = new QListWidgetItem(QIcon(":/images/phone.webp"),"iPhone");
    ui ->listWidget -> addItem(money);
    ui ->listWidget -> addItem(phone);
    ui->listWidget->setVisible(false);
    connect(ui ->viewInventory, SIGNAL(clicked(bool)),this,SLOT(displayInventory()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listWidget_itemDoubleClicked()
{
    QMessageBox msg;
    msg.setText(ui->listWidget->currentItem()->text());
    msg.exec();
}

void MainWindow::displayInventory()
{
   if(ui ->listWidget->isVisible())
   {
      ui->listWidget->setVisible(false);
   }
   else
   {
      ui->listWidget->setVisible(true);
   }

}
