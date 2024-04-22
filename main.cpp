#include <QCoreApplication>
#include<QTextStream>
#include<QDebug>
#include <conio.h>
#include "consoleloger.h"
#include "filemanager.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ConsoleLoger lg;
    FileManager manager(&lg);







    return a.exec();
}
