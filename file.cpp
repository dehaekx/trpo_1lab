#include "file.h"
File::File()
{
    this->fileName = QString("");
    this->filePath = QString("");
    this->fileSize = 0;
    this->fileExist = false;
}

File::File(const QString &path)
{
    QFileInfo fileinfo(path);
    if (fileinfo.exists())
    {
        this->fileName = fileinfo.fileName();
        this->filePath = fileinfo.filePath();
        this->fileSize = fileinfo.size();
        this->fileExist = fileinfo.exists();
    }
}

QString File::getFileName() {return fileName;}
QString File::getFilePath() {return filePath;}
qint64 File::getFileSize() {return fileSize;}
bool File::getFileExist() {return fileExist;}

void File::setFileName(QString name) {this->fileName = name;}
void File::setFilePath(QString path) {this->filePath = path;}
void File::setFileSize(qint64 size) {this->fileSize = size;}
void File::setFileExist(bool newExist) {this->fileExist = newExist;}
