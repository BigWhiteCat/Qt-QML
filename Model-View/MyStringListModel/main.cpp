#include <QApplication>
#include <QListView>
#include <QTableView>

#include "MyStringListModel.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QStringList list;
    list << "a"
         << "b"
         << "c";

    MyStringListModel model(list);

    QListView listView;
    listView.setModel(&model);
    listView.show();

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    model.insertRows(3, 2);
    model.removeRows(0, 1);

    app.exec();
}
