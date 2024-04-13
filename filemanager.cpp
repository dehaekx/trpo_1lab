#include "filemanager.h"

FileManager::FileManager() {}

void FileManager::addFile(File* file)
{
    files.append(file);
    connect(file, &File::fileChanged,
            this, &FileManager::fileChangedSlot); // устанавливаем сигнал filechanged с слотом fileChangedSlot

}

void FileManager::fileChangedSlot(File* file)
{
    if (file)
    {
        if (file->size() > 0)
        {
            qDebug() << "File " << file->getFileName() << "существует и размер:" << file->getFileSize() << "bytes\n";
        }
        else
        {
            qDebug() << "File " << file->getFileName() << "существует, но пустой\n";
        }
    }
    else
    {
        qDebug() << "File " << file->getFileName() << "не существует\n";
    }
}
