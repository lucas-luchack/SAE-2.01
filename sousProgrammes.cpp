#include "sousProgrammes.h"
#include <iostream>
#include <vector>
#include "image.h"
#include "lecteur.h"
using namespace std;


void saisieVerifChoixActionSurImageCourante(char& pChoixAction)
{
    cout << endl << endl;
    while (true)
    {
        cout  << endl ;
        cout << "ACTIONS :" << "  A-vancer" << "  R-eculer" << "  C-hanger de diaporama " << "  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'Q'))
        {
            break;
        }
    }
}

void charger(Lecteur* pLecteur, Images& pImages)
{
    Diaporama *diaporama;

    // Diaporama par défaut
    diaporama = new Diaporama("Diaporama par defaut", 1);
    diaporama->ajouterImage(pImages[0], 1);
    pLecteur->chargerDiaporama(diaporama);

    // Diaporama de Pantxika
    diaporama = new Diaporama("Diaporama Pantxika", 2);
    diaporama->ajouterImage(pImages[8], 3);
    diaporama->ajouterImage(pImages[1], 2);
    diaporama->ajouterImage(pImages[2], 4);
    diaporama->ajouterImage(pImages[6], 1);
    pLecteur->chargerDiaporama(diaporama);

    // Diaporama de Thierry
    diaporama = new Diaporama("Diaporama Thierry", 4);
    diaporama->ajouterImage(pImages[4], 1);
    diaporama->ajouterImage(pImages[1], 2);
    diaporama->ajouterImage(pImages[2], 3);
    diaporama->ajouterImage(pImages[3], 4);
    pLecteur->chargerDiaporama(diaporama);

    // Diaporama de Yann
    diaporama = new Diaporama("Diaporama Yann", 3);
    diaporama->ajouterImage(pImages[10], 2);
    diaporama->ajouterImage(pImages[1], 1);
    diaporama->ajouterImage(pImages[5], 4);
    diaporama->ajouterImage(pImages[3], 3);
    pLecteur->chargerDiaporama(diaporama);

    // Diaporama de Manu
    diaporama = new Diaporama("Diaporama Manu", 1);
    diaporama->ajouterImage(pImages[4], 4);
    diaporama->ajouterImage(pImages[5], 3);
    diaporama->ajouterImage(pImages[9], 2);
    diaporama->ajouterImage(pImages[6], 1);
    pLecteur->chargerDiaporama(diaporama);

    // Diaporama de Lucas
    diaporama = new Diaporama("Diaporama de Lucas", 5);
    diaporama->ajouterImage(pImages[1], 10);
    diaporama->ajouterImage(pImages[2], 5);
    diaporama->ajouterImage(pImages[3], 3);
    diaporama->ajouterImage(pImages[4], 8);
    diaporama->ajouterImage(pImages[5], 7);
    diaporama->ajouterImage(pImages[6], 1);
    diaporama->ajouterImage(pImages[7], 9);
    diaporama->ajouterImage(pImages[8], 2);
    diaporama->ajouterImage(pImages[9], 4);
    diaporama->ajouterImage(pImages[10], 6);
    pLecteur->chargerDiaporama(diaporama);
}

void charger (Images& pImages) {
    Image *imageACharger;
    imageACharger = new Image("", "objet", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Blanche Neige", "personnage", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Alice", "personnage", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Mickey", "animal", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Pinnochio", "personnage", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("chateau", "objet", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Minnie", "personnage", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Bambi", "animal", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Picsou internet", "animal", "C:\\cartesDisney\\Disney_17.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Tigrou", "animal", "C:\\cartesDisney\\Disney_39.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("Tarzan", "personnage", "C:\\cartesDisney\\Disney_38.gif");
    pImages.push_back(imageACharger);
}
