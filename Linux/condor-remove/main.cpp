#include "Condor_Remove.h"

int main(int /*argc*/, char *argv[]) {
    Condor_Remove remove;
    remove.remove(atoi(argv[1]), atoi(argv[2]));

    return 0;
}
