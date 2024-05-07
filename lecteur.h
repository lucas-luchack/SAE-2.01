#ifndef LECTEUR_H
#define LECTEUR_H

#include "diaporama.h"

enum ModeLecteur {automatique, manuel};

class Lecteur
{

public:
    Lecteur();

    void changerDiaporama(unsigned int);
    void chargerDiaporama(Diaporama*);

    Diaporamas getDiaporamas() const;
    Diaporama* getCurrentDiaporama() const;

    unsigned int getDiaporamasCount() const;

    // Programmes provisoires pour les versions NON GRAPHIQUES
    void afficherImageDiapo() const;
    unsigned int saisieVerifChoixDiaporama() const;
    void declencherAction(char);

private:
    ModeLecteur mode;
    unsigned int numDiaporama;
    Diaporamas diaporamas;
    unsigned int id;

};

#endif // LECTEUR_H
