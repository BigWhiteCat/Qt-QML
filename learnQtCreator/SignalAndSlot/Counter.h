#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject {
    Q_OBJECT
  public:
    explicit Counter(QObject *parent = nullptr);

    int Value();

  signals:
    void valueChanged(int value);

  public slots:
    void setValue(int value);
    void increment();
    void decrement();

  private:
    int value;
};

#endif  // COUNTER_H
