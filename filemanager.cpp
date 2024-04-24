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
    qDebug()<< "filepath: " << filePath << Qt::endl;
    File temp(filePath);
    for (auto x: this->files)
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
    if(this->files.size() > 0){
        QFileInfo fileInfoNow;
        for(auto file : this->files){
            fileInfoNow.setFile(file.getFilePath());
            this->checkFileChanges(fileInfoNow, file);
        }
        return;
    }
    emit log_signal("No files\n");
}

void FileManager::checkFileChanges(const QFileInfo& currentfile, File& fileOld){
    QString message = "Name: " + fileOld.getFileName() + " , path: " + fileOld.getFilePath();
    if(currentfile.exists() == fileOld.getFileExist())
    {
        if(!currentfile.exists() || currentfile.size() == fileOld.getFileSize()) // изменений не произошло
            return;

                    // Изменился размер
        message += " - EXIST, " + QString("OLD SIZE: ") + QString::number(fileOld.getFileSize())
                   +" NEW SIZE: " + QString::number(currentfile.size());

        fileOld.setFileSize(currentfile.size());
    }
    else
    {
        if(currentfile.exists()) // create file
        {
            message += QString(" - EXIST, ") + QString(" SIZE: ") + QString::number(currentfile.size());
        }
        else
        {                       // delete
            message+=QString(" - NOT EXIST ");
        }
        fileOld.setFileSize(currentfile.size());
        fileOld.setFileExist(currentfile.exists());
    }
    emit log_signal(message);
}
