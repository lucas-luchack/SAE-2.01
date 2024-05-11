#include "image.h"

Image::Image(string titre, string categorie, string chemin):
    titre(titre),
    categorie(categorie),
    chemin(chemin)
{}

Image::~Image()
{

}

string Image::getCategorie() const
{
    return this->categorie;
}

string Image::getTitre() const
{
    return this->titre;
}

string Image::getChemin() const
{
    return this->chemin;
}