#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "modele.h"
#include "lecteurvue.h"

class Presentation
{
public:
    Presentation();

    void setVue(LecteurVue*);
    void setModele(Modele*);

    LecteurVue* getVue() const;
    Modele* getModele() const;

private:
    LecteurVue* vue;
    Modele* modele;
};

#endif // PRESENTATION_H
