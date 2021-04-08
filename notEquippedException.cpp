#include "gamePopup.h"
#include <exception>

using namespace std;

class NotEquippedException : public exception {
public:
    const char *what() const throw(){
        GamePopup msg;
        msg.setText("You are currently holding no item");
        msg.setInformativeText("Select a weapon from armoury to attack");
        msg.exec();
    }
};
