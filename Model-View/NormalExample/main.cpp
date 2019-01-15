#include <QApplication>
#include <QTableView>

#include "NormalExample.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QTableView tableView;
    NormalModel model;
    tableView.setModel(&model);
    tableView.show();

    return app.exec();
}
