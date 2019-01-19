#include "Painting.h"

Painting::Painting() : year(0) {
}

Painting::Painting(const QString &theTitle, const QString &theArtist, int theYear) : title(theTitle), artist(theArtist), year(theYear) {
}

QString Painting::getTitle() const {
    return title;
}

void Painting::setTitle(const QString &value) {
    title = value;
}

QString Painting::getArtist() const {
    return artist;
}

void Painting::setArtist(const QString &value) {
    artist = value;
}

int Painting::getYear() const {
    return year;
}

void Painting::setYear(int value) {
    year = value;
}

QDataStream &operator<<(QDataStream &out, const Painting &thePainting) {
    out << thePainting.getTitle() << "    " << thePainting.getArtist() << "    " << thePainting.getYear();
    return out;
}

QDataStream &operator>>(QDataStream &in, Painting &thePainting) {
    QString title;
    QString artist;
    int year;

    in >> title >> artist >> year;

    Painting tempPainting(title, artist, year);
    thePainting = tempPainting;

    return in;
}
