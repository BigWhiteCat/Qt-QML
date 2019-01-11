#include <QDialogButtonBox>
#include <QListWidget>
#include <QVBoxLayout>

#include "FlowChartSymbolPicker.h"

FlowChartSymbolPicker::FlowChartSymbolPicker(const QMap<int, QString> &symbolMap, QWidget *parent) : QDialog(parent) {
    id = -1;
    listWidget = new QListWidget;
    listWidget->setIconSize(QSize(60, 60));

    QMapIterator<int, QString> i(symbolMap);
    while (i.hasNext()) {
        i.next();
        QListWidgetItem *item = new QListWidgetItem(i.value(), listWidget);
        item->setIcon(iconForSymbol(i.value()));
        item->setData(Qt::UserRole, i.key());
    }

    dialogButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(dialogButtonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(dialogButtonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(listWidget);
    mainLayout->addWidget(dialogButtonBox);
    this->setLayout(mainLayout);
    this->resize(QSize(600, 500));
    this->setWindowTitle(tr("Flow Chart Symbol Picker"));
}

FlowChartSymbolPicker::~FlowChartSymbolPicker() {
}

void FlowChartSymbolPicker::done(int result) {
    id = -1;

    if (result == QDialog::Accepted) {
        QListWidgetItem *item = listWidget->currentItem();
        if (item) {
            id = item->data(Qt::UserRole).toInt();
        }
    }
    QDialog::done(result);
}

QIcon FlowChartSymbolPicker::iconForSymbol(const QString &symbolName) {
    QString fileName = ":/images/" + symbolName.toLower();
    fileName.replace(" ", "-");
    return QIcon(fileName);
}
