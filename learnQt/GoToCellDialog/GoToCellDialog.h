#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include "ui_GoToCellDialog.h"

/*!
 * \brief The GoToCellDialog class one privides the objects, the other one privide the methods.
 */
class GoToCellDialog : public QDialog, public Ui::GoToCellDialog {
    Q_OBJECT

  public:
    GoToCellDialog(QWidget *parent = nullptr);

  private slots:
    void on_lineEdit_textChanged();
};

#endif  // GOTOCELLDIALOG_H
