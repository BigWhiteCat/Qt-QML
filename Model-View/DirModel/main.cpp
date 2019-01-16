#include <QApplication>

#include "DirectoryViewer.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    DirectoryViewer directoryViewer;
    directoryViewer.show();

    return app.exec();
}
