#include <QCoreApplication>

#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "C++ Style Info Message";
    return a.exec();
}
