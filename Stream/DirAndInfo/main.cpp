#include <iostream>

#include <QCoreApplication>

#include "Declaration.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QString path;

    QStringList arguments = QCoreApplication::arguments();
    if (arguments.count() > 1) {
        path = arguments.at(1);
    }

    std::cout << "Space used by images in " << qPrintable(path) << " and its subdirectories is " << (imageSpace(path) / 1024) << " KB" << std::endl;

    return app.exec();
}
