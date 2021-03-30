#include "Game.h"

Game::Game()
{
    QGraphicsScene *scene = new QGraphicsScene();
    scene -> setSceneRect(0,0,1920,1080);
    setScene(scene);
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
//    setFixedSize(1920,1080);
    setWindowFlags(Qt::Window);
    setWindowTitle(QString::fromStdString(::gameTitle));

    inventory = new Inventory;
    inventory -> move(scene->width()- 300,scene->height()- 300); //-300 -300
    inventory->show();
//    inventory ->setMovement(QListView::Static);
//    inventory ->setMouseTracking(false); want to make the inventory immovable


    // perhaps could make fn that does all this stuff call addToGame perhaps
    Item *item2 = new Item("iPhone",400,3,":/images/phone.webp");
    item2 -> setPos(400,400);
    scene -> addItem(item2);
    connect(item2,SIGNAL(itemSelected(Item *)),inventory,SLOT(addToInventory(Item*)));
    connect(item2,SIGNAL(itemSelected(Item *)),this,SLOT(removeFromScene(Item *)));

    Item *item3 = new Item("Android Phone",200,3,":/images/phone.webp");
    item3 -> setPos(800,800);
    scene -> addItem(item3);
    connect(item3,SIGNAL(itemSelected(Item *)),inventory,SLOT(addToInventory(Item*)));
    connect(item3,SIGNAL(itemSelected(Item *)),this,SLOT(removeFromScene(Item *)));

    Weapon *weapon = new Weapon("Sword",50,2,1,":/images/sword.png");
    weapon -> setPos(500,700);
    scene -> addItem(weapon);
    connect(weapon,SIGNAL(itemSelected(Item *)),inventory,SLOT(addToInventory(Item*)));
    connect(weapon,SIGNAL(itemSelected(Item *)),this,SLOT(removeFromScene(Item *)));

}

void Game::removeFromScene(Item *item)
{
    item->hide();
}
