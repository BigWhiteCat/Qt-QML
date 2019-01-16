#include <QApplication>
#include <QDir>
#include <QFileSystemModel>
#include <QListView>
#include <QModelIndex>
#include <QTreeView>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QFileSystemModel model;
    model.setRootPath(QDir::homePath());

    QListView listView;
    listView.setModel(&model);
    listView.setRootIndex(model.index(QDir::homePath()));

    QTreeView treeView;
    treeView.setModel(&model);
    treeView.setRootIndex(model.index(QDir::homePath()));

    listView.show();
    treeView.show();

    return app.exec();
}
