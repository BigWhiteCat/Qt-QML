#include <QDialogButtonBox>
#include <QList>
#include <QPointF>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>

#include "CoordinateSetter.h"

CoordinateSetter::CoordinateSetter(QList<QPointF> *theCoordinates, QWidget *parent) : QDialog(parent) {
    this->coordinates = theCoordinates;

    tabelWidget = new QTableWidget(0, 2);
    tabelWidget->setHorizontalHeaderLabels(QStringList() << tr("X") << tr("Y"));

    for (int row = 0; row != coordinates->count(); ++row) {
        QPointF point = coordinates->at(row);
        addRow();
        tabelWidget->item(row, 0)->setText(QString::number(point.x()));
        tabelWidget->item(row, 1)->setText(QString::number(point.y()));
    }

    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    QPushButton *addRowButton = buttonBox->addButton(tr("&Add Row"), QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Ok);
    buttonBox->addButton(QDialogButtonBox::Cancel);

    connect(addRowButton, SIGNAL(clicked()), this, SLOT(addRow()));
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabelWidget);
    mainLayout->addWidget(buttonBox);
    this->setLayout(mainLayout);

    setWindowTitle(tr("Coordinate Setter"));
}

void CoordinateSetter::done(int result) {
    if (result == QDialog::Accepted) {
        coordinates->clear();
        for (int row = 0; row != tabelWidget->rowCount(); ++row) {
            double x = tabelWidget->item(row, 0)->text().toDouble();
            double y = tabelWidget->item(row, 1)->text().toDouble();
            coordinates->append(QPointF(x, y));
        }
    }
    QDialog::done(result);
}

void CoordinateSetter::addRow() {
    int row = tabelWidget->rowCount();
    tabelWidget->insertRow(row);

    QTableWidgetItem *item0 = new QTableWidgetItem;
    item0->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    tabelWidget->setItem(row, 0, item0);

    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    tabelWidget->setItem(row, 1, item1);

    tabelWidget->setCurrentItem(item0);
}
