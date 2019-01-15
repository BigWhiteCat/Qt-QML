#ifndef EASYMODEL_H
#define EASYMODEL_H

#include <QAbstractTableModel>

class EasyModel : public QAbstractTableModel {
    Q_OBJECT

  public:
    EasyModel(QAbstractTableModel *parent = nullptr);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif  // EASYMODEL_H
