#include "filemanager.h"

FileManager::FileManager(Loger* lg)
{
    if (lg)
    {
        this->loger = lg;
        connect(this, &FileManager::log_signal, this->loger, &Loger::logMessage); // не точно
    }
}

void FileManager::addFile(const QString &filePath)
{
    File temp(filePath);
    files.push_back(temp);
}

