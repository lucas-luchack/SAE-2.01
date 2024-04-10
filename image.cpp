#include "image.h"

Image::Image(string titre, string categorie, string chemin):
    m_titre(titre),
    m_categorie(categorie),
    m_chemin(chemin)
{}

void Image::creerImage(string titre, string categorie, string chemin)
{
    this->m_titre = titre;
    this->m_categorie = categorie;
    this->m_chemin = chemin;
}

string Image::getCategorie() const
{
    return this->m_categorie;
}

string Image::getTitre() const
{
    return this->m_titre;
}

string Image::getChemin() const
{
    return this->m_chemin;
}

void Image::afficher() const
{
    cout << "image(titre:" << this->getTitre() << ", categorie:"
         << this->getCategorie() << ", chemin:"<< this->getChemin() << ")" << endl;
}
