#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "lecteur.h"
#include "lecteurvue.h"

class Presentation: public QObject
{
    Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);

    void setVue(LecteurVue *);
    void setModele(Lecteur *);

    LecteurVue *getVue() const;
    Lecteur *getModele() const;

private:
    LecteurVue* vue;
    Lecteur* modele;

private slots:
    void received();

    void nextImage() const;
    void previousImage() const;
    void
};

#endif // PRESENTATION_H
