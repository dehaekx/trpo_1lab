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
    File(QString filePath);

        // три геттера
    QString getFileName();
    QString getFilePath();
    qint64 getFileSize();

        // три сеттера
    void setFileName(QString newName);
    void setFilePath(QString newPath);
    void setFileSize(qint64 newSize);

signals: // СИГНАЛ НАШ
    void fileChanged(); // const QString& message

public slots:
    void checkFile();

private:
    bool isFileChanged();

};

#endif // FILE_H
