﻿#include <QApplication>

#include "FindDialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FindDialog w;
    w.show();

    return a.exec();
}
