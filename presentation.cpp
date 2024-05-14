#include "presentation.h"

#include <QObject>
#include <QMessageBox>
#include <QTimer>
#include "selectionform.h"

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(automaticNext()));
}

void Presentation::initialize()
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

void Presentation::received()
{
    qDebug() << "Cliqué";
}

void Presentation::nextImage() const
{
    this->modele->getCurrentDiaporama()->avancer();
    this->updateImage();
    this->changeModeToAuto(false);
}

void Presentation::automaticNext() const
{
    this->modele->getCurrentDiaporama()->avancer();
    this->updateImage();
}

void Presentation::previousImage() const
{
    this->modele->getCurrentDiaporama()->reculer();
    this->updateImage();
    this->changeModeToAuto(false);
}

void Presentation::unloadDiapo() const
{
    this->modele->changerDiaporama(0);
    this->updateDiaporama();
}

void Presentation::loadDiapo() const
{
    SelectionForm selectionDialog;
    selectionDialog.setDiaporamaList(this->modele->getDiaporamas());
    int result = selectionDialog.exec();

    if (result == QDialog::Accepted)
    {
        int selected = selectionDialog.getSelectedDiaporama() + 1;
        this->modele->changerDiaporama(selected);
        this->updateDiaporama();
    }
}

void Presentation::changeMode() const
{
    if (this->modele->getMode() == ModeLecteur::automatique)
    {
        this->modele->setMode(manuel);
        this->timer->stop();
    }
    else
    {
        this->modele->setMode(automatique);
        this->timer->start(this->modele->getCurrentDiaporama()->getVitesseDefilement());
    }

    this->vue->updateModeButton(this->modele->getMode());
}

void Presentation::changeModeToAuto(bool checked) const
{
    if (checked && this->modele->getMode() != automatique)
    {
        this->modele->setMode(automatique);
        this->timer->start(this->modele->getCurrentDiaporama()->getVitesseDefilement());
    }
    else if (!checked && this->modele->getMode() == automatique)
    {
        this->modele->setMode(manuel);
        this->timer->stop();
    }

    this->vue->updateModeButton(this->modele->getMode());
}

void Presentation::changeModeToManuel(bool checked) const
{
    if (checked && this->modele->getMode() != manuel)
    {
        this->modele->setMode(manuel);
        this->timer->stop();
    }
    else if (!checked && this->modele->getMode() == manuel)
    {
        this->modele->setMode(automatique);
        this->timer->start(this->modele->getCurrentDiaporama()->getVitesseDefilement());
    }

    this->vue->updateModeButton(this->modele->getMode());
}

void Presentation::openHelpDialog() const
{
    QMessageBox helpDialog;
    helpDialog.setText("Ce lecteur de diaporama à été réalisé dans le cadre de la SAE 2.02 par trois étudiants de l'IUT de Bayonne et du Pays Basque (département Informatique) :\n\n- ESPIET Lucas\n- RIVRAIS-NOWAKOWSKI Mathis\n- HOARAU Allan");
    helpDialog.setInformativeText("Lecteur de Diaporama / SAE 2.02 / V4-MVP");
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
