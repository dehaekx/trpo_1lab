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
    this->fileName = fileinfo.fileName();
    this->filePath = fileinfo.filePath();
    this->fileSize = fileinfo.size();
    this->fileExist = fileinfo.exists();
}

QString File::getFileName() {return fileName;}
QString File::getFilePath() {return filePath;}
qint64 File::getFileSize() {return fileSize;}
bool File::getFileExist() {return fileExist;}

void File::update()
{
    QFileInfo fileinfo(filePath);
    fileExist = fileinfo.exists();
    fileSize = fileinfo.size();
}

void File::setFileSize(qint64 size) {this->fileSize = size;}
void File::setFileExist(bool newExist) {this->fileExist = newExist;}
