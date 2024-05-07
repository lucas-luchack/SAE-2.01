#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "modele.h"
#include "lecteurvue.h"

class Presentation: public QObject
{
    Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);

    void setVue(LecteurVue *);
    void setModele(Modele *);

    LecteurVue *getVue() const;
    Modele *getModele() const;

private:
    LecteurVue* vue;
    Modele* modele;

private slots:
    void received();
};

#endif // PRESENTATION_H