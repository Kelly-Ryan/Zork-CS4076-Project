#include "Game.h"

Game::Game()
{
    QGraphicsScene *scene = new QGraphicsScene();
    setScene(scene);
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setFixedSize(1000,600);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    setWindowTitle(QString::fromStdString(::gameTitle));

    inventory = new Inventory;
    inventory -> move(width()- 300,height()- 300);
    inventory->show();
    connect(inventory,SIGNAL(itemCollected(GameItem *)),this,SLOT(removeFromScene(GameItem *)));
//    inventory ->setMovement(QListView::Static);
//    inventory ->setMouseTracking(false); want to make the inventory immovable


    // perhaps could make fn that does all this stuff call addToGame perhaps
    Item *item2 = new Item("iPhone",400,3,":/images/phone.webp");
    item2 -> setPos(400,400);
    scene -> addItem(item2);
    connect(item2,SIGNAL(itemSelected(GameItem *)),inventory,SLOT(addToInventory(GameItem*)));

    Item *item3 = new Item("Android Phone",200,3,":/images/phone.webp");
    item3 -> setPos(800,800);
    scene -> addItem(item3);
    connect(item3,SIGNAL(itemSelected(GameItem *)),inventory,SLOT(addToInventory(GameItem*)));

    Weapon *weapon = new Weapon("Sword",50,2,":/images/sword.png");
    weapon -> setPos(500,700);
    scene -> addItem(weapon);
    connect(weapon,SIGNAL(itemSelected(GameItem *)),inventory,SLOT(addToInventory(GameItem*)));

    Enemy *enemy = new Enemy("Monster",":/images/monster.png");
    scene -> addItem(enemy);
}

void Game::removeFromScene(GameItem *item)
{
    item->hide();
}
