#ifndef CONSOLELOGER_H
#define CONSOLELOGER_H
#include "loger.h"
#include <QDebug>
#include <QObject>

class ConsoleLoger: public Loger
{
public:

public slots:
    void logMessage(const QString& message) override;
};

#endif // CONSOLELOGER_H
