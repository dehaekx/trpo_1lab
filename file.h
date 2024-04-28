#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QString>
#include <QFileInfo>
#include <QObject>


class File
{
private:
    QString fileName;
    QString filePath;
    qint64 fileSize;
    bool fileExist;
public:
    File();
    File(const QString &filePath);

        // геттеры
    QString getFileName();
    QString getFilePath();
    qint64 getFileSize();
    bool getFileExist();

    void update();

        // сеттеры
    // void setFileSize(qint64 newSize);
    // void setFileExist(bool newExist);
};

#endif // FILE_H
