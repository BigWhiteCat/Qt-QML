#include <QtWidgets>

#include "SortDialog.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    SortDialog *dialog = new SortDialog;
    dialog->setColumnRange('A', 'F');
    dialog->show();

    return app.exec();
}
