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
    qDebug()<< "filepath: " << filePath << Qt::endl;
    File temp(filePath);
    if (temp.getFileExist())
    {
        File temp(filePath);
        files.push_back(temp);
    }
}

void FileManager::checkfiles()
{
    File temp;
    for (int i = 0; i < files.size(); i++)
    {
        temp.setFilePath(files[i].getFilePath());
        if (temp.getFileExist() != files[i].getFileExist() || temp.getFileSize() != files[i].getFileSize())
        {
            emit log_signal("File" + temp.getFileName() + "is changed. Exist: " + temp.getFileExist() + ". Size: "
                            + temp.getFileSize());
        }
    }
}
