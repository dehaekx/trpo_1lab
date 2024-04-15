#include "filemanager.h"

FileManager::FileManager(Loger* loger): loger(loger)
{
    connect(this, SIGNAL(upd_signal(File*, bool, qint64)),
            this, SLOT(update(File*, bool, qint64)));
}

void FileManager::addFile(File* file)
{
    files.append(file);
    connect(this, SIGNAL(log_signal(QString)),
            loger, SLOT(log(QString)));
}

void FileManager::update(File* F, const bool &ex, const qint64 &s)
{
    if (ex)
        emit log_signal("File " + F->getFileName() + " был изменен. Размер: " + QString::number(s));
    else
        emit log_signal("File " + F->getFileName() + " не был изменен");
}

