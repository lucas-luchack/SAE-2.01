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
