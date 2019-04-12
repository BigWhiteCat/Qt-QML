#include <QCoreApplication>
#include "MathFunctions.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug("6! is %d", MathFunctions::factorial(6));

    return a.exec();
}
