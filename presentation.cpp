#include "presentation.h"

#include <QObject>
#include <QMessageBox>
#import "selectionform.h"

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{

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
}

void Presentation::previousImage() const
{
    this->modele->getCurrentDiaporama()->reculer();
    this->updateImage();
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

void Presentation::openHelpDialog() const
{
    QMessageBox helpDialog;
    helpDialog.setText("Ce lecteur de diaporama à été réalisé dans le cadre de la SAE 2.02 par trois étudiants de l'IUT de Bayonne et du Pays Basque (département Informatique) :\nESPIET Lucas\nRIVRAIS-NOWAKOWSKI Mathis\nHOARAU Allan");
    helpDialog.setInformativeText("Lecteur de Diaporama / SAE 2.02 / V2-MVP");
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
