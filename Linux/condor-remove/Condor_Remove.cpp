#include <iostream>

#include <QProcess>

#include "Condor_Remove.h"

Condor_Remove::Condor_Remove(QObject *parent) : QObject(parent) {
    this->progress = new QProcess(this);
}

Condor_Remove::~Condor_Remove() {
}

void Condor_Remove::remove(int first, int last) const {
    if (first > last) {
        std::cout << "first number greater than the last number." << std::endl;
        return;
    }

    QString cmd = "condor_rm";

    for (; first != last + 1; ++first) {
        QStringList arguments;
        arguments << QString::number(first);
        progress->start(cmd, arguments);
    }
}
