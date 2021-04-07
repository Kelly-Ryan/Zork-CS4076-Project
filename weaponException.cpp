#include "gamePopup.h"
#include <exception>

using namespace std;

class WeaponException : public exception {
    const char *what() const throw(){
        GamePopup msg;
        msg.setText("You must have a weapon equipped to attack!");
        msg.exec();
    }
};
