#include "file.h"
File::File()
{
    this->fileName = QString("");
    this->filePath = QString("");
    this->fileSize = 0;
}

File::File(QString name, QString path):
    fileName(name), filePath(path), fileSize(0)
{
    QFileInfo *fileinfo = new QFileInfo(filePath);
    if (fileinfo)
    {
        this->fileName = QString(fileinfo->fileName());
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


