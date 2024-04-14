#include "file.h"
File::File()
{
    this->fileName = QString("");
    this->filePath = QString("");
    this->fileSize = 0;
}

File::File(QString path)
{
    QFileInfo *fileinfo = new QFileInfo(path);
    if (fileinfo->exists())
    {
        this->fileName = fileinfo->fileName();
        this->filePath = fileinfo->filePath();
        this->fileSize = fileinfo->size();
    }
    delete fileinfo;
}

QString File::getFileName() {return fileName;}
QString File::getFilePath() {return filePath;}
qint64 File::getFileSize() {return fileSize;}

void File::setFileName(QString name) {fileName = name;}
void File::setFilePath(QString path) {filePath = path;}
void File::setFileSize(qint64 size) {fileSize = size;}

bool File::isFileChanged()
{
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists())
    {
        return true; // Файл не существует
    }
    if (fileInfo.size() != fileSize)
    {
        return true; // Размер файла был изменен
    }
    return false; // Файл существует и размер тот же
}

void File::checkFile()
{
    if (isFileChanged())
    {
        emit fileChanged(); // "Файл " + fileName + " был изменен"
    }
}
