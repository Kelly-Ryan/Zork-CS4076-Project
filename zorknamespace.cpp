#include "zorknamespace.h"

using namespace Zork;

QString Zork::toQString(string s)
{
    return QString::fromStdString(s);
}

string Zork::capitalise(string s)
{
    s[0] = toupper(s[0]);
    return s;
}
