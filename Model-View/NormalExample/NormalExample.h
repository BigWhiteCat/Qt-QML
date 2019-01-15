#ifndef NORMALModel_H
#define NORMALModel_H

#include <QAbstractTableModel>

class NormalModel : public QAbstractTableModel {
    Q_OBJECT

  public:
    NormalModel(QAbstractTableModel *parent = nullptr);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif  // NORMALModel_H
