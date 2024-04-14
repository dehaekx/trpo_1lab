#include "filemanager.h"

FileManager::FileManager() {}

FileManager::FileManager(Loger* loger): loger(loger) {}

void FileManager::addFile(File* file)
{
    files.append(file);
    connect(file, &File::fileChanged,
            this, &FileManager::fileChangedSlot(file)); // устанавливаем сигнал filechanged с слотом fileChangedSlot

}

void FileManager::fileChangedSlot(File* file)
{
    if (file)
    {
        loger->logMessage("File " + file->getFileName() + " существует и размер: " + file->getFileSize() + " bytes.");
    }
    else
    {
        loger->logMessage("File " + file->getFileName() + " не существует");
    }
}
