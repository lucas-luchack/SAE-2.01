#include "diaporama.h"

Diaporama::Diaporama(string titre, unsigned int vitesseDefilement):
    titre(titre),
    vitesseDefilement(vitesseDefilement),
    numImageCourante(0)
{}

void Diaporama::triCroissantRang()
{

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
