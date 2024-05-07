#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <iostream>
#include <image.h>
#include <vector>

struct ImageDansDiaporama {
    Image *image;
    unsigned int rang;
};
typedef vector<ImageDansDiaporama> ImagesDansDiaporama;

class Diaporama
{

public:
    Diaporama(string, unsigned int = 1000);
    ~Diaporama();

    std::string getTitre() const;

    void triCroissantRang();
    void ajouterImage(Image*, unsigned int);
    void avancer();
    void reculer();
    unsigned int nbImages() const;
    void remiseAZero();

    ImagesDansDiaporama getImages() const;
    ImageDansDiaporama getImage() const;

private:
    std::string titre;
    unsigned int vitesseDefilement;
    unsigned int numImageCourante;
    ImagesDansDiaporama images;

};

typedef vector<Diaporama*> Diaporamas;

#endif // DIAPORAMA_H
