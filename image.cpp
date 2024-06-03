#include "image.h"

Image::Image(unsigned int id, QString titre, QString categorie, QString chemin):
    id(id),
    titre(titre),
    categorie(categorie),
    chemin(chemin)
{}

Image::~Image()
{

}

unsigned int Image::getId() const
{
    return this->id;
}

QString Image::getCategorie() const
{
    return this->categorie;
}

QString Image::getTitre() const
{
    return this->titre;
}

QString Image::getChemin() const
{
    return this->chemin;
}

void Image::setId(unsigned int id)
{
    this->id = id;
}

void Image::setTitre(QString title)
{
    this->titre = title;
}

void Image::setCategorie(QString categorie)
{
    this->categorie = categorie;
}

void Image::setChemin(QString chemin)
{
    this->chemin = chemin;
}
