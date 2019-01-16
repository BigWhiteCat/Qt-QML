#ifndef MYSTRINGLISTMODEL_H
#define MYSTRINGLISTMODEL_H

#include <QAbstractListModel>

class MyStringListModel : public QAbstractListModel {
  public:
    MyStringListModel(const QStringList& stringList, QObject* parent = nullptr);

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex& index, int role) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    virtual bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
    virtual bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;

  private:
    QStringList stringList;
};

#endif  // MYSTRINGLISTMODEL_H
