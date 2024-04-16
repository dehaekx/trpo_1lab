#include "filemanager.h"

FileManager::FileManager(Loger* lg)
{
    if (lg)
    {
        loger = lg;
        connect(this, SIGNAL(upd_signal(File*, bool, qint64)), this, SLOT(update(File*, bool, qint64)));
    }
}

void FileManager::addFile(File* file)
{
    // нужно проверку сделать на file.exist
    files.push_back(file);
    connect(this, SIGNAL(log_signal(QString)), loger, SLOT(logMessage(QString)));
}

void FileManager::update(File* F, const bool &ex, const qint64 &s) // нужно дописать все проверки и выводить правильный вывод
{
    if (ex)
        emit log_signal("File " + F->getFileName() + " был изменен. Размер: " + QString::number(s));
    else
        emit log_signal("File " + F->getFileName() + " не был изменен");
}

