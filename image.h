#ifndef IMAGE_H
#define IMAGE_H

#include <QString>

#include <vector>

// Classe de manipulation d'éléments de type Image

class Image
{

public:
    Image(QString = "", QString = "", QString = "");
    ~Image();

    QString getTitre() const;
    QString getCategorie() const;
    QString getChemin() const;

private:
    QString titre;
    QString categorie;
    QString chemin;

};

typedef std::vector<Image*> Images;

#endif // IMAGE_H
