#include "EasyModel.h"

EasyModel::EasyModel(QAbstractTableModel *parent) {
    Q_UNUSED(parent);
}

int EasyModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 2;
}

int EasyModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;
}

QVariant EasyModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return QString("Row%1, Column%2").arg(index.row() + 1).arg(index.column() + 1);
    }

    return QVariant();
}
