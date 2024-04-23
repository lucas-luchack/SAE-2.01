#include <iostream>
#include <vector>
#include "image.h"
#include "diaporama.h"
#include "lecteur.h"
#include "sousProgrammes.h"
using namespace std;


int main()
{
    /* -------------------------------------------------------------------------------------
     * Charge les images et les diaporamas 'en dur' ... en attendant l'implantation de la BD :
     * - Charger les images et diaporamas
     * Dans un second temps, ces contenus proviendront d'une base de données
     --------------------------------------------------------------------------------------*/
    Images images;          // les images
    Diaporamas diaporamas;  // les diaporamas
    Lecteur lecteur;

    // Chargement des urls des images, chargement des diaporamas
    charger(images);
    charger(lecteur, images);

    unsigned int taille_diaporamas = diaporamas.size();

    // Tri des images contenues dans les diaporamas pour les placer dans l'ordre d'apparition (rang) souhaité par l'utilisateur
    for (unsigned int posDiapo = 0; posDiapo < taille_diaporamas; posDiapo++)
    {
        cout << "Tri de : " << diaporamas[posDiapo]->getTitre() << " (" << posDiapo << ")" << endl;
        diaporamas[posDiapo]->triCroissantRang();
    }


    /* ---------------------
     * Lecteur de diaporamas
     * --------------------- */

    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction ;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles
    while (true)
    {

        /* Affichage à l'écran des infos de l'image courante dans son diaporama   */
        system("cls");  // effacer l'écran
        lecteur.afficherImageDiapo();


        /* Menu des actions possibles (saisie choix utilisateur) :
         * A-vancer, R-eculer, C-hanger de diaporama, Q-uitter */

        saisieVerifChoixActionSurImageCourante(choixAction);
        if (choixAction == 'Q')
        {
            break;
        }

        /* Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter) */
        system("cls");  // effacer l'écran
        lecteur.declencherAction(choixAction);
    }

    /* Fin
       --------------*/
      cout << "Au revoir " << endl;
      return 0;
}

