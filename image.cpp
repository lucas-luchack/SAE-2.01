#include "image.h"

Image::Image(QString titre, QString categorie, QString chemin):
    titre(titre),
    categorie(categorie),
    chemin(chemin)
{}

Image::~Image()
{

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
