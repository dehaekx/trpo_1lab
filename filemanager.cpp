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
    // нужно проверку сделать на file.exist // может на правильный путь еще
    if (file)
    {
    files.push_back(file);
        emit log_signal(("File ") + file->getFileName() +
                    (" added. Size: ") + QString::number(file->getFileSize()));
    }
}

void FileManager::update(File* F, const bool &ex, const qint64 &s) // нужно дописать все проверки и выводить правильный вывод
{
    if (ex) // Файл существует, файл был изменен - на экран выводится факт существования файла, сообщение о том что файл был изменен и его размер
    {
        F->setFileSize(s);
        emit log_signal("File " + F->getFileName() + " был изменен. Размер: " + QString::number(s));
    }
    else
    {
        emit log_signal("File " + F->getFileName() + " не был изменен");
    }
}

