#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QVector>
#include <QObject>
#include "File.h"

class FileManager
{
public:
    QVector<File*> files;

public:
    void addFile(File* file);
    void updateFile(QString fileName, qint64 fileSize);
};

#endif // FILEMANAGER_H
