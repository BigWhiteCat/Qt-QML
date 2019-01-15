#include <QApplication>
#include <QTableView>

#include "HeaderModel.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    HeaderModel model;
    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    return app.exec();
}
