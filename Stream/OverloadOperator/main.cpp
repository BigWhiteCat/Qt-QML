#include "Painting.h"

int main(int /*argc*/, char** /*argv*/) {
    Painting paint("Title", "xiaohai", 2019);

    QDataStream out;
    out << paint;

    return 0;
}
