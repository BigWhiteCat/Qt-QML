#ifndef CITEMODEL_H
#define CITEMODEL_H

#include <QAbstractTableModel>

class CiteModel : public QAbstractTableModel {
    Q_OBJECT

  public:
    CiteModel(QObject *parent = nullptr);

    void setCities(const QStringList &citeNames);
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual QVariant headerData(int section, const Qt::Orientation orientation, int role) const override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

  private:
    int offsetOf(int row, int column) const;

    QStringList cities;
    QVector<int> distance;
};

#endif  // CITEMODEL_H
