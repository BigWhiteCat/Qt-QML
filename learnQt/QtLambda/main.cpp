#include <QApplication>
#include <QDebug>
#include <QPushButton>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QPushButton button("I am a button");
    QObject::connect(&button, &QPushButton::clicked, [](bool) { qDebug() << "You clicked me."; });
    button.show();

    return app.exec();
}
