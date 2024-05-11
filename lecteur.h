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

    ModeLecteur getMode() const;
    
    Diaporamas getDiaporamas() const;
    Diaporama* getCurrentDiaporama() const;

    unsigned int getDiaporamasCount() const;

private:
    ModeLecteur mode;
    unsigned int numDiaporama;
    Diaporamas diaporamas;
    
};

#endif // LECTEUR_H
