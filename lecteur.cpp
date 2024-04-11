#include "lecteur.h"

Lecteur::Lecteur()
{

}

void Lecteur::changerDiaporama(unsigned int numDiapo)
{
    this->numDiaporama = numDiapo;
}

Diaporamas Lecteur::getDiaporamas() const
{
    return this->diaporamas;
}

Diaporama* Lecteur::getCurrentDiaporama() const
{
    return this->diaporamas[this->numDiaporama];
}
