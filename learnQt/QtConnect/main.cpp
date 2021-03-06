﻿#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QPushButton button("I am a button");
    QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
    button.show();

    return app.exec();
}
