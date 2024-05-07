#ifndef SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H
#define SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H

#include "image.h"
#include "diaporama.h"
#include "lecteur.h"

using namespace std;


void saisieVerifChoixActionSurImageCourante(char& pChoixAction);

/* Sous-programmes provisoires pour versions antérieures à l'implantation de la BD
----------------------------------------------------------------------------------*/
void charger (Images& pImages);
/* Chargement du tableau des images avec seules les informations textuelles de quelques images.
   Dans une version ultérieure, ces informations seront stockées dans une Base de Données.
*/

void charger (Lecteur* pLecteur, Images& pImages);
/* Chargement du tableau des diaporamas avec des diaporamas préalablement construits 'en dur'.
   Dans une version ultérieure, le diaporama courant affiché par le Lecteur de diaporamas sera chargé à partir
   d'une base de données.
*/

#endif // SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H
