#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "lecteur.h"
#include "lecteurvue.h"

class Presentation: public QObject
{
    Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);

    void initialize();

    void setVue(LecteurVue *);
    void setModele(Lecteur *);

    LecteurVue *getVue() const;
    Lecteur *getModele() const;

private:
    LecteurVue* vue;
    Lecteur* modele;

    void updateImage() const;
    void updateDiaporama() const;

private slots:
    void received();
    void openHelpDialog() const;

    void nextImage() const;
    void previousImage() const;
    void unloadDiapo() const;
    void loadDiapo() const;

    void changeMode() const;
    void changeModeToAuto(bool) const;
    void changeModeToManuel(bool) const;

};

#endif // PRESENTATION_H
