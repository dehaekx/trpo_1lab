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
    FileManager(Loger* loger);
    void addFile(File* file);
    //void setLog(Loger *log);

signals:
    void log_signal(const QString &str);
    void upd_signal(File* F, const bool &Exist, const qint64 &size);

public slots:
    //void check();
    void update(File* F, const bool &Exist, const qint64 &size);
};

#endif // FILEMANAGER_H
