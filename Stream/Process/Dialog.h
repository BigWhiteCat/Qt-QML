#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT

  public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

  private slots:
    void browse();
    void convertImage();
    void updateOutputTextPlaintEdit();
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void processError(QProcess::ProcessError error);

  private:
    Ui::Dialog *ui;
    QProcess process;
    QString targetFile;
};

#endif  // DIALOG_H
