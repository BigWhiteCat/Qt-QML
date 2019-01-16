#ifndef CURRENCYMODEL_H
#define CURRENCYMODEL_H

#include <QAbstractTableModel>

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class CurrencyModel : public QAbstractTableModel {
    Q_OBJECT

  public:
    CurrencyModel(QObject *parent = nullptr);

    void setCurrencyMap(const QMap<QString, double> &theMap);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  private:
    QString currencyAt(int offset) const;

    QMap<QString, double> currencyMap;
};

#endif  // CURRENCYMODEL_H
