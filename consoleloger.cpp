#include "consoleloger.h"

void ConsoleLoger::logMessage(const QString& message)
{
    qDebug() << "ConsoleLog: " << message << Qt::endl;
}
