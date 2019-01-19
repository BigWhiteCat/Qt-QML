#ifndef PAINTING_H
#define PAINTING_H

#include <QDataStream>

class Painting {
  public:
    Painting();
    Painting(const QString &title, const QString &artist, int year);

    QString getTitle() const;
    void setTitle(const QString &value);

    QString getArtist() const;
    void setArtist(const QString &value);

    int getYear() const;
    void setYear(int value);

  private:
    QString title;
    QString artist;
    int year;
};

QDataStream &operator<<(QDataStream &out, const Painting &thePainting);
QDataStream &operator>>(QDataStream &in, Painting &thePainting);

#endif  // PAINTING_H
