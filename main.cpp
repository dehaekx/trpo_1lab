#include <QCoreApplication>
#include<QTextStream>
#include<QDebug>
#include <conio.h>
#include "file.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Создаем объекты файлов и менеджера файлов
    QFile file1("file1.txt");
    QFile file2("file2.txt");

    return a.exec();
}
