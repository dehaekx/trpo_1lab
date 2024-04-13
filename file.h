#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QString>
#include <QFileInfo>


class File : public QFile
{
private:
    QString fileName;
    QString filePath;
    qint64 fileSize;
public:
    File(QString fileName, QString filePath);

        // три геттера
    QString getFileName();
    QString getFilePath();
    qint64 getFileSize();

        // три сеттера
    void setFileName(QString newName);
    void setFilePath(QString newPath);
    void setFileSize(qint64 newSize);

};

#endif // FILE_H
