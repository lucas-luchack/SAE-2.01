#ifndef IMAGE_H
#define IMAGE_H

#include <QString>

#include <vector>

// Classe de manipulation d'éléments de type Image

class Image
{

public:
    Image(unsigned int, QString = "", QString = "", QString = "");
    ~Image();

    QString getTitre() const;
    QString getCategorie() const;
    QString getChemin() const;

    void setTitre(QString);
    void setCategorie(QString);
    void setChemin(QString);

private:
    unsigned int id;
    QString titre;
    QString categorie;
    QString chemin;

};

typedef std::vector<Image*> Images;

#endif // IMAGE_H
