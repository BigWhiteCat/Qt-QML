#include <QDir>
#include <QFileDialog>
#include <QPlainTextEdit>
#include <QPushButton>

#include "Dialog.h"

#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);

    ui->convertPushButton->setEnabled(false);
    connect(ui->browseButton, &QPushButton::clicked, this, &Dialog::browse);
    connect(ui->convertPushButton, &QPushButton::clicked, this, &Dialog::convertImage);
    connect(ui->cancelPushButton, &QPushButton::clicked, this, &Dialog::reject);
    connect(&process, &QProcess::readyReadStandardError, this, &Dialog::updateOutputTextPlaintEdit);
    connect(&process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(processFinished(int, QProcess::ExitStatus)));
    connect(&process, SIGNAL(QProcess::error(QProcessError)), this, SLOT(processError(QProcessError)));
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::browse() {
    QString initialName = ui->sourceFileLineEdit->text();
    if (initialName.isEmpty()) {
        initialName = QDir::currentPath();
    }
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose File"), initialName);
    fileName = QDir::toNativeSeparators(fileName);

    if (!fileName.isEmpty()) {
        ui->sourceFileLineEdit->setText(fileName);
        ui->convertPushButton->setEnabled(true);
    }
}

void Dialog::convertImage() {
    QString sourceFile = ui->sourceFileLineEdit->text();
    QString targetFile =
        QFileInfo(sourceFile).path() + QDir::separator() + QFileInfo(sourceFile).baseName() + "." + ui->comboBox->currentText().toLower();
    ui->convertPushButton->setEnabled(false);
    ui->plainTextEdit->clear();

    QStringList args;

    if (ui->enhanceCheckBox->isChecked()) {
        args << "-enhance";
    }
    if (ui->monochromeCheckBox->isChecked()) {
        args << "-monochrome";
    }

    process.start("convert", args);
}

void Dialog::updateOutputTextPlaintEdit() {
    QByteArray newData = process.readAllStandardError();
    ui->plainTextEdit->setPlainText(QString::fromLocal8Bit(newData));
}

void Dialog::processFinished(int exitCode, QProcess::ExitStatus exitStatus) {
    if (exitStatus == QProcess::CrashExit) {
        ui->plainTextEdit->appendPlainText(tr("Conversion program crashed"));
    } else if (exitCode != 0) {
        ui->plainTextEdit->appendPlainText(tr("Conversion failed"));
    } else {
        ui->plainTextEdit->appendPlainText(tr("File %1 created").arg(targetFile));
    }

    ui->convertPushButton->setEnabled(true);
}

void Dialog::processError(QProcess::ProcessError error) {
    if (error == QProcess::FailedToStart) {
        ui->plainTextEdit->appendPlainText(tr("Conversion program not found"));
        ui->convertPushButton->setEnabled(true);
    }
}
