#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QVector>
#include <QObject>
#include "File.h"
#include <QDebug>

class FileManager: public QObject
{
    Q_OBJECT
private:
    QVector<File*> files;

public:
    FileManager();
    void addFile(File* file);
    void updateFile(QString fileName, qint64 fileSize);
public slots:
    void fileChangedSlot(File* file);

};

#endif // FILEMANAGER_H
