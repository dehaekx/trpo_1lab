#include "consoleloger.h"

ConsoleLoger::ConsoleLoger() {}

void ConsoleLoger::logMessage(const QString& message)
{
    qDebug() << "ConsoleLog: " << message;
}
