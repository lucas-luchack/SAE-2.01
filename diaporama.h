#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <iostream>
#include <image.h>
#include <vector>

struct ImageDansDiaporama {
    Image *image;       // rang de l'image dans le tableau d'images (vector<Images>)
                        // = ordre de chargement initial des images dans la table des images
    unsigned int rang;  // rang de l'image dans le diaporama
                        // = ordre d'affichage choisi par l'utilisateur lors de la création du diaporama
};
typedef vector<ImageDansDiaporama> ImagesDansDiaporama;

class Diaporama
{

public:
    Diaporama(string, unsigned int = 1000);
    ~Diaporama();

    void triCroissantRang();
    void ajouterImage(Image*, unsigned int);
    void avancer();
    void reculer();
    unsigned int nbImages() const;

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
