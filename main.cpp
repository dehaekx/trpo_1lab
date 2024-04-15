#include <QCoreApplication>
#include<QTextStream>
#include<QDebug>
#include <conio.h>
#include "file.h"
#include "consoleloger.h"
#include "filemanager.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ConsoleLoger lg;
    FileManager manager(&lg);
    QObject::connect(&manager, SIGNAL(log_signal(QString)), &lg, SLOT(log(QString)));

    File *f;




    return a.exec();
}
