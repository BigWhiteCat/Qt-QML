#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("Signa And Slot");

    QSpinBox *spinBox = new QSpinBox;
    spinBox->setRange(0, 130);
    QSlider *slider = new QSlider;
    slider->setRange(0, 130);
    slider->setOrientation(Qt::Horizontal);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);

    spinBox->setValue(29);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);

    mainWindow->setLayout(layout);
    mainWindow->show();

    return app.exec();
}
