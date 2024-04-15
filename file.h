#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QString>
#include <QFileInfo>
#include <QObject>


class File : public QFile
{
    Q_OBJECT
private:
    QString fileName;
    QString filePath;
    qint64 fileSize;
public:
    File();
    File(const QString &filePath);

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
