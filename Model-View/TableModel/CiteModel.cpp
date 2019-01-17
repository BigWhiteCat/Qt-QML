

#include "CiteModel.h"

CiteModel::CiteModel(QObject *parent) : QAbstractTableModel(parent) {
}

void CiteModel::setCities(const QStringList &citeNames) {
    beginResetModel();
    cities = citeNames;
    distance.resize(cities.count() * (cities.count() - 1) / 2);
    distance.fill(0);
    endResetModel();
}

int CiteModel::rowCount(const QModelIndex & /*parent*/) const {
    return cities.count();
}

int CiteModel::columnCount(const QModelIndex & /*parent*/) const {
    return cities.count();
}

QVariant CiteModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    if (role == Qt::TextAlignmentRole) {
        return static_cast<int>(Qt::AlignRight | Qt::AlignVCenter);
    } else if (role == Qt::DisplayRole) {
        if (index.row() == index.column()) {
            return 0;
        }
        int offset = offsetOf(index.row(), index.column());
        return distance[offset];
    }
    return QVariant();
}

bool CiteModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && index.row() != index.column() && role == Qt::EditRole) {
        int offset = offsetOf(index.row(), index.column());
        distance[offset] = value.toInt();

        QModelIndex transposedIndex = createIndex(index.column(), index.row());
        emit dataChanged(index, index);
        emit dataChanged(transposedIndex, transposedIndex);

        return true;
    }
    return false;
}

QVariant CiteModel::headerData(int section, const Qt::Orientation /*orientation*/, int role) const {
    if (role == Qt::DisplayRole) {
        return cities[section];
    }

    return QVariant();
}

Qt::ItemFlags CiteModel::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if (index.row() != index.column()) {
        flags = flags | Qt::ItemIsEditable;
    }
    return flags;
}

int CiteModel::offsetOf(int row, int column) const {
    if (row < column) {
        qSwap(row, column);
    }
    return (row * (row - 1) / 2) + column;
}
