#include "lecteur.h"
#include <iostream>
using namespace std;

Lecteur::Lecteur()
{

}

void Lecteur::changerDiaporama(unsigned int numDiapo)
{
    this->numDiaporama = numDiapo;
    this->getCurrentDiaporama()->remiseAZero();
}

void Lecteur::chargerDiaporama(Diaporama *diapo)
{
    this->diaporamas.push_back(diapo);
}

void Lecteur::lireDiaporama() const
{

}

Diaporamas Lecteur::getDiaporamas() const
{
    return this->diaporamas;
}

Diaporama* Lecteur::getCurrentDiaporama() const
{
    return this->diaporamas[this->numDiaporama];
}

unsigned int Lecteur::getDiaporamasCount() const
{
    return this->diaporamas.size();
}

void Lecteur::afficherImageDiapo() const
{
    cout << endl << endl;
    cout << "DIAPORAMA : " << this->getCurrentDiaporama()->getTitre() << endl << endl;
    cout << this->getCurrentDiaporama()->getImage().rang << " sur " << this->getCurrentDiaporama()->nbImages() << " / ";
    this->getCurrentDiaporama()->getImage().image->afficher();
}

unsigned int Lecteur::saisieVerifChoixDiaporama() const
{
    unsigned int choixSaisi;
    int choixDiaporama;

    for (;;)
    {
        system("cls");
        cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;

        for (unsigned int num = 1; num < this->getDiaporamasCount(); num++)
        {
            cout << num << ": " << this->getDiaporamas()[num]->getTitre();
            if (num != this->getDiaporamasCount() - 1) { cout << endl; }
        }

        cout << "....... votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1) && (choixDiaporama < static_cast<int>(this->getDiaporamasCount())))
        {
            break;
        }
    }

    return choixDiaporama;
}

void Lecteur::declencherAction(char choixAction)
{
    unsigned int choixDiaporama;

    switch (choixAction)
    {
    case 'A':
        this->getCurrentDiaporama()->avancer();
        this->afficherImageDiapo();
        break;

    case 'R':
        this->getCurrentDiaporama()->reculer();
        this->afficherImageDiapo();
        break;

    case 'C':
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = this->saisieVerifChoixDiaporama();

        // Changer de diaporama
        this->changerDiaporama(choixDiaporama);
        break;

    default: break;
    }
}
