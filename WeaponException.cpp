#include <QMessageBox>
#include <exception>

using namespace std;

class WeaponException : public exception {
    const char *what() const throw(){
        QMessageBox msg;
        msg.setText("You must have a weapon equipped to attack!");
        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setStyleSheet("background-color:gray;border-style:outset");
        msg.move(350,300);
        msg.exec();
    }
};
