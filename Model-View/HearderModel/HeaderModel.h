#ifndef HEADERMODEL_H
#define HEADERMODEL_H

#include <QAbstractTableModel>

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

class HeaderModel : public QAbstractTableModel {
    Q_OBJECT
  public:
    HeaderModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

  public slots:
    void timerHit();

  private:
    QTimer *timer;
};

#endif  // HEADERMODEL_H
