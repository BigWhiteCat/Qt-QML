#ifndef LIST_H
#define LIST_H

#include <QObject>

class List : public QObject {
    Q_OBJECT
  public:
    explicit List(QObject *parent = nullptr);
    List(const QString &dirName, QObject *parent = nullptr);

    void listFile() const;

    void setDir(const QString &value);

  signals:

  public slots:

  private:
    const QString changeSize(qint64 fileSize) const;
    QString dir;
};

#endif  // LIST_H
