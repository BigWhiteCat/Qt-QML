#include <QApplication>
#include <QTableView>

#include "CiteModel.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QStringList cites;
    cites << "KaiFeng"
          << "ShangHai"
          << "ZhengZhou"
          << "QingDao"
          << "NingBo"
          << "Xi'an"
          << "HaiErBin";

    CiteModel cityModel;
    cityModel.setCities(cites);

    QTableView tableView;
    tableView.setModel(&cityModel);
    tableView.setAlternatingRowColors(true);
    tableView.show();

    return app.exec();
}
