#include "Clock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Clock w;
  w.show();

  return a.exec();
}
