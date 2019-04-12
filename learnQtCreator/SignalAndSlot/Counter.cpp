#include "Counter.h"

Counter::Counter(QObject *parent) : QObject(parent), value(0) {
}

int Counter::Value() {
    return this->value;
}

void Counter::setValue(int value) {
    if (this->value != value) {
        this->value = value;
        emit valueChanged(value);
    }
}

void Counter::increment() {
    setValue(Value() + 1);
}

void Counter::decrement() {
    setValue(Value() - 1);
}
