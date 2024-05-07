#include "presentation.h"

#include <QObject>

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{

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
}
