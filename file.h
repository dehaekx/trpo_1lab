#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QString>


class File : public QFile
{
private:
    QString fileName;
    QString filePath;
    qint64 fileSize;

public:
    File(QString fileName, QString filePath);

    QString getFileName();
    QString getFilePath();
    qint64 getFileSize();

    void setFileName(QString newName);
    void setFilePath(QString newPath);
    void setFileSize(qint64 newSize);

};

#endif // FILE_H
