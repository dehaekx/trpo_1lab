#ifndef LOGER_H
#define LOGER_H

#include <QObject>
#include <QString>

class Loger
{
public:
    Loger();
    virtual void logMessage(const QString& message) = 0; // pure virtual function
};

#endif // LOGER_H
