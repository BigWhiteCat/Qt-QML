#include <QCoreApplication>

#include "List.h"

int main(int argc, char *argv[]) {
    List list;

    if (argc == 2) {
        list.setDir(argv[1]);
    }

    list.listFile();
}
