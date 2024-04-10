#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
using namespace std;

#include <vector>

// Classe de manipulation d'éléments de type Image

class Image
{

public:
    Image(string = "", string = "", string = "");

private:
    string titre;
    string categorie;
    string chemin;

protected:
    void creerImage(string = "", string = "", string = "");
    string getTitre() const;
    string getCategorie() const;
    string getChemin() const;
    void afficher() const;

};

typedef vector<Image> Images;

#endif // IMAGE_H
