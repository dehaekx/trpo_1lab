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
    QVector<File> files;
    Loger * loger;

public:
    FileManager(Loger* lg);
    void addFile(const QString &filePath);
    void checkfiles();
    void checkFileChanges(const QFileInfo& fileNow, File& fileOld);
signals:
    void log_signal(const QString &str);
};

#endif // FILEMANAGER_H
