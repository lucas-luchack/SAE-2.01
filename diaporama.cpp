#include "diaporama.h"


#include <QDebug>
#include <vector>

Diaporama::Diaporama(unsigned int id, QString titre, unsigned int vitesseDefilement):
    titre(titre),
    id(id),
    vitesseDefilement(vitesseDefilement),
    numImageCourante(0)
{}

Diaporama::~Diaporama()
{

}

QString Diaporama::getTitre() const
{
    return this->titre;
}

void Diaporama::triCroissantRang()
{
    unsigned int taille = this->nbImages();

    ImageDansDiaporama imageDansDiapo;
    for (unsigned int ici = taille-1; ici >= 1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (this->images[i].rang > this->images[i+1].rang)
            {
                // echanger les 2 éléments
                imageDansDiapo = this->images[i];
                this->images[i] = this->images[i+1];
                this->images[i+1] = imageDansDiapo;
            }
        }
    }
}

void Diaporama::avancer()
{
    if (this->numImageCourante == (this->nbImages() - 1))
    {
        this->numImageCourante = 0;
    }
    else
    {
        this->numImageCourante += 1;
    }
}

void Diaporama::reculer()
{
    if (this->numImageCourante == 0)
    {
        this->numImageCourante = this->nbImages() - 1;
    }
    else
    {
        this->numImageCourante -= 1;
    }
}

unsigned int Diaporama::nbImages() const
{
    return this->images.size();
}

void Diaporama::reset()
{
    this->numImageCourante = 0;
}

ImagesDansDiaporama Diaporama::getImages() const
{
    return this->images;
}

ImageDansDiaporama Diaporama::getImage() const
{
    return this->images[this->numImageCourante];
}

void Diaporama::setId(unsigned int id)
{
    this->id = id;
}

void Diaporama::setTitre(QString titre)
{
    this->titre = titre;
}

void Diaporama::ajouterImage(Image *image, unsigned int rang)
{
    ImageDansDiaporama imgDansDiapo;
    imgDansDiapo.image = image;
    imgDansDiapo.rang = rang;

    this->images.push_back(imgDansDiapo);
}

unsigned int Diaporama::getId() const
{
    return this->id;
}

unsigned int Diaporama::getVitesseDefilement() const
{
    return this->vitesseDefilement;
}

void Diaporama::setVitesseDefilement(unsigned int speed)
{
    this->vitesseDefilement = speed;
}

std::vector<Image*> Diaporama::removeAllImages(std::vector<Image*> deletedImages)
{
    ImageDansDiaporama img;
    while(!this->images.empty())
    {
        img = this->images.back();

        unsigned int taille = deletedImages.size();
        bool found = false;
        for (unsigned int i = 0; i < taille; i++)
        {
            if (deletedImages[i] == img.image)
            {
                found = true;
            }
        }

        if (!found)
        {
            deletedImages.push_back(img.image);
            delete img.image;
        }

        this->images.pop_back();
    }

    return deletedImages;
}
