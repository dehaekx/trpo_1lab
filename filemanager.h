#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QVector>
#include <QObject>
#include "File.h"
#include <QDebug>
#include "loger.h"

class FileManager: public QObject
{
    Q_OBJECT
private:
    QVector<File*> files;
    Loger * loger;
public:
    FileManager();
    FileManager(Loger* loger);
    void addFile(File* file);
    void updateFile(QString fileName, qint64 fileSize);
public slots:
    void fileChangedSlot(File* file);

};

#endif // FILEMANAGER_H
