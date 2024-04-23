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
    void lireDiaporama() const;

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

};

#endif // LECTEUR_H
