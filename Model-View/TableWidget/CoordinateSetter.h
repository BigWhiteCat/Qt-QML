#ifndef COORDINATESETTER_H
#define COORDINATESETTER_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QTableWidget;
QT_END_NAMESPACE

class CoordinateSetter : public QDialog {
    Q_OBJECT

  public:
    CoordinateSetter(QList<QPointF> *coordinates, QWidget *parent = nullptr);

    virtual void done(int result) override;

  private slots:
    void addRow();

  private:
    QTableWidget *tabelWidget;
    QDialogButtonBox *buttonBox;
    QList<QPointF> *coordinates;
};

#endif  // COORDINATESETTER_H
