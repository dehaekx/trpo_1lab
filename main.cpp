#include <QCoreApplication>
#include<QDebug>

#include "consoleloger.h"
#include "filemanager.h"

#include <QDir>
#include <QTimer>

#include <chrono>
#include <thread>


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    ConsoleLoger logger;
    FileManager filemanager(&logger);

    QString currentReposiroty = QDir::currentPath().section("/", 0, -2);
    qDebug() << "Direction: " << currentReposiroty;
    QString test = currentReposiroty + "/trpo_1lab/test_files/";
    // QString test = currentFilePathProject + "/trpo_1lab/test_files/test2.docx";
    // QString test = currentFilePathProject + "/trpo_1lab/test_files/test3.jpg";

    int count_of_files;
    qDebug() << "Input counts of files which you want to track: ";
    cin >> count_of_files;
    for (int i = 0; i < count_of_files; i++)
    {
        qDebug() << "Enter your file" << i << "name with extension: "; // test1.txt
        QString name_of_file;
        cin >> name_of_file;
        test += name_of_file;
        filemanager.addFile(test);
        test = test.section("/", 0, -2);
        test += "/";
        //qDebug() << test << Qt::endl;
    }

    //filemanager.checkfiles();

    // filemanager.addFile(test);

    while (true)
    {
        std::this_thread::sleep_for( std::chrono::milliseconds(1500));
        filemanager.checkfiles();
    };

    return a.exec();
}
