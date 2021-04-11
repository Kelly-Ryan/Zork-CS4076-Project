#ifndef ZORKNAMESPACE_H
#define ZORKNAMESPACE_H

#include <string>
#include <QString>
#include <QDebug>

using std::string;

namespace Zork{
   QString toQString(string s);
   string capitalise(string s);
}

#endif // ZORKNAMESPACE_H
