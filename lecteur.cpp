#include "lecteur.h"
#include <iostream>
using namespace std;

Lecteur::Lecteur():
    mode(manuel),
    numDiaporama(0)
{}

void Lecteur::changerDiaporama(unsigned int numDiapo)
{
    this->numDiaporama = numDiapo;
    this->getCurrentDiaporama()->reset();
}

void Lecteur::chargerDiaporama(Diaporama *diapo)
{
    this->diaporamas.push_back(diapo);
}

void Lecteur::setMode(ModeLecteur mode)
{
    this->mode = mode;
}

Diaporamas Lecteur::getDiaporamas() const
{
    return this->diaporamas;
}

Diaporama* Lecteur::getCurrentDiaporama() const
{
    return this->diaporamas[this->numDiaporama];
}

unsigned int Lecteur::getDiaporamasCount() const
{
    return this->diaporamas.size();
}

ModeLecteur Lecteur::getMode() const
{
    return this->mode;
}
