#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <image.h>
#include <vector>

#include <QString>

struct ImageDansDiaporama {
    Image *image;
    unsigned int rang;
};
typedef std::vector<ImageDansDiaporama> ImagesDansDiaporama;

class Diaporama
{

public:
    Diaporama(unsigned int, QString, unsigned int = 1000);
    ~Diaporama();

    QString getTitre() const;
    unsigned int getId() const;
    unsigned int getVitesseDefilement() const;

    void triCroissantRang();
    void ajouterImage(Image*, unsigned int);
    void avancer();
    void reculer();
    unsigned int nbImages() const;
    void reset();
    std::vector<Image*> removeAllImages(std::vector<Image*>);

    ImagesDansDiaporama getImages() const;
    ImageDansDiaporama getImage() const;

    void setId(unsigned int);
    void setTitre(QString);
    void setVitesseDefilement(unsigned int);

private:
    QString titre;
    unsigned int id;
    unsigned int vitesseDefilement;
    unsigned int numImageCourante;
    ImagesDansDiaporama images;

};

typedef std::vector<Diaporama*> Diaporamas;

#endif // DIAPORAMA_H
