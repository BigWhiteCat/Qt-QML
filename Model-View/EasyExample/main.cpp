#include <QApplication>
#include <QTableView>

#include "EasyModel.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QTableView tableView;
    EasyModel model;
    tableView.setModel(&model);
    tableView.show();

    return app.exec();
}
