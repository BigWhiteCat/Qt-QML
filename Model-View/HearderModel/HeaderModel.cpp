#include <QTime>
#include <QTimer>

#include "HeaderModel.h"

HeaderModel::HeaderModel(QObject *parent) : QAbstractTableModel(parent) {
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHit()));
    timer->start();
}

int HeaderModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;
}

int HeaderModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;
}

QVariant HeaderModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole) {
        if (row == 0 && col == 0) {
            return QTime::currentTime().toString();
        }
    }

    return QVariant();
}

QVariant HeaderModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("First");
                case 1:
                    return QString("Second");
                case 2:
                    return QString("Third");
            }
        }
    }

    return QVariant();
}

void HeaderModel::timerHit() {
    QModelIndex topLeft = createIndex(0, 0);
    emit dataChanged(topLeft, topLeft);
}
