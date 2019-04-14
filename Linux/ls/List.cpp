#include <cmath>
#include <iomanip>
#include <iostream>

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>

#include "List.h"

List::List(QObject *parent) : QObject(parent), dir(".") {
}

List::List(const QString &dirName, QObject *parent) : QObject(parent), dir(dirName) {
}

void List::listFile() const {
    QDir tempDir(dir);
    qint64 totalSize = 0;
    foreach (QFileInfo fileInfo, tempDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs)) {
        totalSize += fileInfo.size();
        std::cout << "\033[32m" << std::setiosflags(std::ios::left) << std::setw(20) << changeSize(fileInfo.size()).toStdString() << "   ";
        std::cout << "\033[31m" << fileInfo.fileName().toStdString() << std::endl;
    }
    std::cout << "Total Size: " << changeSize(totalSize).toStdString() << std::endl;
}

void List::setDir(const QString &value) {
    dir = value;
}

const QString List::changeSize(qint64 fileSize) const {
    QString result;
    if (fileSize > 1024 * 1024 * 1024) {  // GB
        result += QString::number(floor(fileSize / std::pow(1024, 3))) + "GB ";
        fileSize = fileSize % (1024 * 1024 * 1024);
    }
    if (fileSize > 1024 * 1024) {  // MB
        result += QString::number(floor(fileSize / std::pow(1024, 2))) + "MB ";
        fileSize = fileSize % (1024 * 1024);
    }
    if (fileSize > 1024) {
        result += QString::number(floor(fileSize / std::pow(1024, 1))) + "KB ";
        fileSize = fileSize % 1024;
    }
    return result + QString::number(fileSize);
}
