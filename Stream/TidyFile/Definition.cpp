#include <QTextStream>
#include <iostream>

#include "Declaration.h"

void tidyFile(QIODevice *inDevice, QIODevice *outDevice) {
    QTextStream in(inDevice);
    QTextStream out(outDevice);

    const int TabSize = 8;
    int endCount = 0;
    int spaceCount = 0;
    int column = 0;

    QChar ch;

    while (!in.atEnd()) {
        in >> ch;

        if (ch == '\n') {
            ++endCount;
            spaceCount = 0;
            column = 0;
        } else if (ch == '\t') {
            int size = TabSize - (column % TabSize);
            spaceCount += size;
            column += size;
        } else if (ch == ' ') {
            ++spaceCount;
            ++column;
        } else {
            while (endCount > 0) {
                out << '\n';
                --endCount;
                column = 0;
            }
            while (spaceCount > 0) {
                out << ' ';
                --spaceCount;
                ++column;
            }
            out << ch;
            ++column;
        }
    }
    out << '\n';
}
