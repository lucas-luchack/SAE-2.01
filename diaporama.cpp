#include "diaporama.h"

Diaporama::Diaporama(string titre, unsigned int vitesseDefilement):
    m_titre(titre),
    m_vitesseDefilement(vitesseDefilement),
    m_numImageCourante(0)
{}

void Diaporama::triCroissantRang()
{

}

void Diaporama::avancer()
{
    if (this->m_numImageCourante == (this->nbImages() - 1))
    {
        this->m_numImageCourante = 0;
    }
    else
    {
        this->m_numImageCourante += 1;
    }
}

void Diaporama::reculer()
{
    if (this->m_numImageCourante == 0)
    {
        this->m_numImageCourante = this->nbImages() - 1;
    }
    else
    {
        this->m_numImageCourante -= 1;
    }
}

unsigned int Diaporama::nbImages() const
{
    return this->m_images.size();
}
