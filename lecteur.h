#ifndef LECTEUR_H
#define LECTEUR_H

#include "diaporama.h"

enum ModeLecteur {automatique, manuel};

class Lecteur
{

public:
    Lecteur();
    void changerDiaporama(unsigned int);

private:
    ModeLecteur mode;
    unsigned int numDiaporama;
    Diaporamas *diaporamas;

};

#endif // LECTEUR_H
