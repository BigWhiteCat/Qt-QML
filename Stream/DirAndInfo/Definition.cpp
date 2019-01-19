#include <QByteArray>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QImageReader>

#include "Declaration.h"

qlonglong imageSpace(const QString &path) {
    QDir dir(path);
    qlonglong size = 0;
    QStringList filers;

    foreach (QByteArray format, QImageReader::supportedImageFormats()) {
        qDebug() << format;
        filers += "*." + format;
    }

    foreach (QString file, dir.entryList(filers, QDir::Files)) { size += QFileInfo(dir, file).size(); }

    foreach (QString dir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) { imageSpace(path + QDir::separator() + dir); }

    return size;
}
