#include "file.h"

File::File(QString name, QString path): fileName(name), filePath(path), fileSize(0) {}

QString File::getFileName() {return fileName;}
QString File::getFilePath() {return filePath;}
qint64 File::getFileSize() {return fileSize;}

void File::setFileName(QString name) {fileName = name;}
void File::setFilePath(QString path) {filePath = path;}
void File::setFileSize(qint64 size) {fileSize = size;}
