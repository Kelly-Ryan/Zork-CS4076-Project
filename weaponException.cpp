#include "gamePopup.h"
#include <exception>

using namespace std;

class WeaponException : public exception {
public:
    const char *what() const throw(){
        GamePopup msg;
        msg.setText("You are currently holding no item.");
        msg.setInformativeText("To attack you must select a weapon from inventory");
        msg.exec();
    }
};
