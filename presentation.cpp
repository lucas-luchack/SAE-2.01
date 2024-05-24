#include "presentation.h"

#include <QObject>
#include <QMessageBox>
#include <QTimer>
#include <QInputDialog>
#include "selectionform.h"
#include "sousProgrammes.h"

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(automaticNext()));
}

void Presentation::initialize() const
{
    this->updateDiaporama();
}

void Presentation::setVue(LecteurVue *vue)
{
    this->vue = vue;
}

void Presentation::setModele(Lecteur *modele)
{
    this->modele = modele;
}

LecteurVue* Presentation::getVue() const
{
    return this->vue;
}

Lecteur* Presentation::getModele() const
{
    return this->modele;
}

void Presentation::nextImage() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->avancer();
        this->updateImage();
        this->changeModeToAuto(false);
    }
}

void Presentation::automaticNext() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->avancer();
        this->updateImage();
    }
}

void Presentation::previousImage() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->reculer();
        this->updateImage();
        this->changeModeToAuto(false);
    }
}

void Presentation::unloadDiapo() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->changerDiaporama(0);
        this->modele->removeAllDiapo();
        this->vue->resetInterface();
        this->timer->stop();
    }
}

void Presentation::loadDiapo() const
{
    SelectionForm selectionDialog;
    selectionDialog.setDiaporamaList(this->modele->getDiaporamas());
    int result = selectionDialog.exec();

    if (result == QDialog::Accepted && this->modele->getDiaporamasCount() != 0)
    {
        int selected = selectionDialog.getSelectedDiaporama() + 1;
        this->modele->changerDiaporama(selected);
        this->timer->stop();
        this->updateDiaporama();
    }
}

void Presentation::loadAllDiapo() const
{

    if(this->modele->getDiaporamasCount()==0)
    {
        Images images;
        charger(images);
        charger(this->modele, images);

        unsigned int taille_diaporamas = this->modele->getDiaporamasCount();

        for (unsigned int posDiapo = 0; posDiapo < taille_diaporamas; posDiapo++)
        {
            this->modele->getDiaporamas()[posDiapo]->triCroissantRang();
        }

        this->initialize();
    }

}



void Presentation::changeMode() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        if (this->modele->getMode() == ModeLecteur::automatique)
        {
            this->modele->setMode(manuel);
            this->timer->stop();
        }
        else
        {
            this->modele->setMode(automatique);
            this->resetTimerSpeed();
        }

        this->vue->updateModeButton(this->modele->getMode());
    }
}

void Presentation::changeModeToAuto(bool checked) const
{
    if (this->modele->getDiaporamasCount() != 0) {
        if (checked && this->modele->getMode() != automatique)
        {
            this->modele->setMode(automatique);
            this->resetTimerSpeed();
        }
        else if (!checked && this->modele->getMode() == automatique)
        {
            this->modele->setMode(manuel);
            this->timer->stop();
        }

        this->vue->updateModeButton(this->modele->getMode());
    }
}

void Presentation::changeModeToManuel(bool checked) const
{
    if (this->modele->getDiaporamasCount() != 0) {
        if (checked && this->modele->getMode() != manuel)
        {
            this->modele->setMode(manuel);
            this->timer->stop();
        }
        else if (!checked && this->modele->getMode() == manuel)
        {
            this->modele->setMode(automatique);
            this->resetTimerSpeed();
        }

        this->vue->updateModeButton(this->modele->getMode());
    }
}

void Presentation::select1SecSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->setVitesseDefilement(1000);
        this->resetTimerSpeed();
    }
}

void Presentation::select5SecSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->setVitesseDefilement(5000);
        this->resetTimerSpeed();
    }
}

void Presentation::select10SecSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->setVitesseDefilement(10000);
        this->resetTimerSpeed();
    }
}

void Presentation::selectOwnSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        bool ok = false;
        double result = QInputDialog::getDouble(this->vue, "Vitesse de défilement", "Entrez la vitesse de défilement en secondes", 1, 0, 50000, 1, &ok);

        if (ok)
        {
            this->modele->getCurrentDiaporama()->setVitesseDefilement(result*1000);
            this->resetTimerSpeed();
        }
    }
}

void Presentation::openHelpDialog() const
{
    QMessageBox helpDialog;
    helpDialog.setText("Ce lecteur de diaporama à été réalisé dans le cadre de la SAE 2.02 par trois étudiants de l'IUT de Bayonne et du Pays Basque (département Informatique) :\n\n- ESPIET Lucas\n- RIVRAIS-NOWAKOWSKI Mathis\n- HOARAU Allan");
    helpDialog.setInformativeText("Lecteur de Diaporama / SAE 2.02 / V5-MVP");
    helpDialog.setIcon(QMessageBox::Information);
    helpDialog.exec();
}

void Presentation::updateImage() const
{
    this->vue->updateImage(
                    QString::fromStdString(this->modele->getCurrentDiaporama()->getImage().image->getTitre()),
                    QString::fromStdString(this->modele->getCurrentDiaporama()->getImage().image->getCategorie()),
                    this->modele->getCurrentDiaporama()->getImage().rang,
                    QString::fromStdString(this->modele->getCurrentDiaporama()->getImage().image->getChemin())
                );
}

void Presentation::updateDiaporama() const
{
    this->vue->updateDiaporama(
                    QString::fromStdString(this->modele->getCurrentDiaporama()->getTitre()),
                    this->modele->getCurrentDiaporama()->nbImages()
                );
    
    this->modele->getCurrentDiaporama()->reset();
    this->updateImage();
}

void Presentation::resetTimerSpeed() const
{
    this->timer->stop();
    if (this->modele->getMode() == ModeLecteur::automatique) {
        this->timer->start(this->modele->getCurrentDiaporama()->getVitesseDefilement());
    }
}
