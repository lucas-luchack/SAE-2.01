#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "lecteur.h"
#include "lecteurvue.h"

class Presentation: public QObject
{
    Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);

    void initialize() const;

    void setVue(LecteurVue *);
    void setModele(Lecteur *);

    LecteurVue *getVue() const;
    Lecteur *getModele() const;

private:
    LecteurVue* vue;
    Lecteur* modele;
    QTimer* timer;
    Database *db;

    void updateImage() const;
    void updateDiaporama() const;

    void resetTimerSpeed() const;

private slots:
    void openHelpDialog() const;

    void nextImage() const;
    void automaticNext() const;
    void previousImage() const;

    void unloadDiapo() const;
    void loadDiapo() const;
    void loadAllDiapo() const;

    void changeMode() const;
    void changeModeToAuto(bool) const;
    void changeModeToManuel(bool) const;

    void select1SecSpeed() const;
    void select5SecSpeed() const;
    void select10SecSpeed() const;
    void selectOwnSpeed() const;

};

#endif // PRESENTATION_H
