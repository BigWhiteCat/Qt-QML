#ifndef CONDOR_REMOVE_H
#define CONDOR_REMOVE_H

#include <QObject>
#include <QtGlobal>

QT_BEGIN_NAMESPACE
class QProcess;
QT_END_NAMESPACE

class Condor_Remove : public QObject {
    Q_OBJECT

  public:
    Condor_Remove(QObject *parent = nullptr);
    virtual ~Condor_Remove();

    virtual void remove(int first, int last) const;

  private:
    QProcess *progress;
};

#endif  // CONDOR_REMOVE_H
