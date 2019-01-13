#include <QTimer>

#include "Clock.h"

Clock::Clock(QWidget *parent) : QWidget(parent) {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    this->setWindowTitle(tr("Clock"));
    this->resize(200, 200);
}

Clock::~Clock() {
}
