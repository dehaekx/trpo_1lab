#ifndef CONSOLELOGER_H
#define CONSOLELOGER_H
#include "loger.h"
#include <QDebug>

class ConsoleLoger: public Loger
{
public:
    ConsoleLoger();
    virtual void logMessage(const QString& message) override;
};

#endif // CONSOLELOGER_H
