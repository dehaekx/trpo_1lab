#include "filemanager.h"

FileManager::FileManager(Loger* lg)
{
    if (lg)
    {
        this->loger = lg;
        connect(this, &FileManager::log_signal, this->loger, &Loger::logMessage);
    }
}

void FileManager::addFile(const QString &filePath)
{
    qDebug() << "filepath: " << filePath << Qt::endl;
    File temp(filePath);
    for (auto x: this->files) // Проверим, что еще раз файл тот же не добавим
    {
        if (temp.getFilePath() == x.getFilePath())
        {
            emit log_signal("File already in filemanager\n");
            return;
        }
    }
    if (temp.getFileExist())
    {
        files.push_back(temp);
    }
}

void FileManager::checkfiles()
{
    if (this->files.size() > 0)
    {
        QFileInfo currentfile;
        for(auto & file : this->files)
        {
            currentfile.setFile(file.getFilePath());
            this->checkFileChanges(currentfile, file);
        }
        return;
    }
    emit log_signal("No files");
}

void FileManager::checkFileChanges(const QFileInfo& currentfile, File& fileOld)
{
    QString message = "Name: " + fileOld.getFileName() + " , path: " + fileOld.getFilePath();

    if (currentfile.exists() == fileOld.getFileExist())
    {
        if (currentfile.size() == fileOld.getFileSize())   // изменений не произошло
        {
            //message += " - EXIST, " + QString(" SIZE: ") + QString::number(fileOld.getFileSize());
            return;
        }
        else // Изменился размер
        {
            //qDebug() << "currentfile:" << currentfile.size() << ",   fileOld" << fileOld.getFileSize() << Qt:: endl;
            message += " - EXIST, " + QString("OLD SIZE: ") + QString::number(fileOld.getFileSize())
                   + " NEW SIZE: " + QString::number(currentfile.size());
            //fileOld.setFileSize(currentfile.size());
            fileOld.update();
        }
    }
    else
    {
        if (currentfile.exists()) // старый не сущест, а новый существует
        {
            message += QString(" - EXIST, ") + QString(" SIZE: ") + QString::number(currentfile.size());
        }
        else
        {
            message += QString(" - NOT EXIST ");
        }
        //fileOld.setFileExist(currentfile.exists());
        fileOld.update();
    }
    emit log_signal(message);
}
