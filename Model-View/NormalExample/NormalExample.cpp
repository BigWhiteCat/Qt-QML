#include <QBrush>
#include <QDebug>
#include <QFont>

#include "NormalExample.h"

NormalModel::NormalModel(QAbstractTableModel *parent) {
    Q_UNUSED(parent);
}

int NormalModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 2;
}

int NormalModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;
}

QVariant NormalModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();

    qDebug() << QString("row %1, col %2, row %3").arg(row).arg(col).arg(role);

    switch (role) {
        case Qt::DisplayRole:
            if (row == 0 && col == 1) {
                return QString("<---left");
            }
            if (row == 1 && col == 1) {
                return QString("right--->");
            }
            return QString("Row%1, Column%2").arg(row + 1).arg(col + 1);
            break;

        case Qt::FontRole:
            if (row == 0 && col == 0) {
                QFont boldFont;
                boldFont.setBold(true);
                return boldFont;
            }
            break;

        case Qt::BackgroundRole:
            if (row == 1 && col == 2) {
                QBrush redBackground(Qt::red);
                return redBackground;
            }
            break;

        case Qt::TextAlignmentRole:
            if (row == 1 && col == 1) {
                return Qt::AlignRight + Qt::AlignVCenter;
            }
            break;

        case Qt::CheckStateRole:
            if (row == 1 && col == 0) {
                return Qt::Checked;
            }
            break;

        default:
            break;
    }

    return QVariant();
}
