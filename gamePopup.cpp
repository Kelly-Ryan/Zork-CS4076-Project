#include "gamePopup.h"

GamePopup::GamePopup()
{
    setWindowFlags(FramelessWindowHint);
    setStyleSheet("background-color:gray;border-style:outset");
    move(340,300);
}
