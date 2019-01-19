#include <iostream>

#include <QCoreApplication>
#include <QFile>
#include <QImage>
#include <QMap>

int main(int /*argc*/, char ** /*argv*/) {
    // QCoreApplication app(argc, argv);

    quint32 n;
    QImage image;
    QMap<QString, QColor> map;

    QFile file("facts.dat");
    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Cannot open file for reading: " << qPrintable(file.errorString()) << std::endl;
        return -1;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_10);

    in >> n >> image >> map;

    file.close();

    std::cout << n;

    //    return app.exec();
}
