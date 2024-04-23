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

void charger(Lecteur& pLecteur, Images& pImages)
{
    Diaporama *diaporama;

    // Diaporama par défaut
    diaporama = new Diaporama("Diaporama par defaut", 1);
    diaporama->ajouterImage(pImages[0], 1);
    pLecteur.chargerDiaporama(diaporama);

    // Diaporama de Pantxika
    diaporama = new Diaporama("Diaporama Pantxika", 2);
    diaporama->ajouterImage(pImages[4], 3);
    diaporama->ajouterImage(pImages[1], 2);
    diaporama->ajouterImage(pImages[2], 4);
    diaporama->ajouterImage(pImages[3], 1);
    pLecteur.chargerDiaporama(diaporama);

    // Diaporama de Thierry
    diaporama = new Diaporama("Diaporama Thierry", 4);
    diaporama->ajouterImage(pImages[4], 1);
    diaporama->ajouterImage(pImages[1], 2);
    diaporama->ajouterImage(pImages[2], 3);
    diaporama->ajouterImage(pImages[3], 4);
    pLecteur.chargerDiaporama(diaporama);

    // Diaporama de Yann
    diaporama = new Diaporama("Diaporama Yann", 3);
    diaporama->ajouterImage(pImages[4], 2);
    diaporama->ajouterImage(pImages[1], 1);
    diaporama->ajouterImage(pImages[2], 4);
    diaporama->ajouterImage(pImages[3], 3);
    pLecteur.chargerDiaporama(diaporama);

    // Diaporama de Manu
    diaporama = new Diaporama("Diaporama Manu", 1);
    diaporama->ajouterImage(pImages[4], 4);
    diaporama->ajouterImage(pImages[1], 3);
    diaporama->ajouterImage(pImages[2], 2);
    diaporama->ajouterImage(pImages[3], 1);
    pLecteur.chargerDiaporama(diaporama);
}

void charger (Images& pImages) {
    Image *imageACharger;
    imageACharger = new Image("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);
    imageACharger = new Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}
