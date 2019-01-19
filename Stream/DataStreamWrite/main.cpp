#include <iostream>

#include <QCoreApplication>
#include <QDataStream>
#include <QFile>
#include <QImage>
#include <QMap>

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    QImage image("flower.jpg");

    QMap<QString, QColor> map;
    map.insert("red", Qt::red);
    map.insert("green", Qt::green);
    map.insert("blue", Qt::blue);

    QFile file("facts.dat");
    if (!file.open(QIODevice::WriteOnly)) {
        std::cerr << "Cannot open file for writing: " << qPrintable(file.errorString()) << std::endl;
        return -1;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_10);
    out << quint32(8) << image << map;

    return app.exec();
}
