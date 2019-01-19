#include <QFile>
#include <iostream>

#include "Declaration.h"

int main(int /*argc*/, char ** /*argv*/) {
    QFile inFile("Definition.cpp");
    if (!inFile.open(QIODevice::ReadOnly)) {
        std::cerr << qPrintable(inFile.errorString());
    }

    QFile outFile;
    if (!outFile.open(stdout, QIODevice::WriteOnly)) {
        std::cerr << qPrintable(outFile.errorString());
    }

    tidyFile(&inFile, &outFile);

    return 0;
}
