#include "lecteurvue.h"
#include "lecteur.h"
#include "presentation.h"

#include "image.h"
#include "sousProgrammes.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LecteurVue w;
    Lecteur *m = new Lecteur;
    Presentation *p = new Presentation;

    Images images;
    charger(images);
    charger(m, images);

    unsigned int taille_diaporamas = m->getDiaporamasCount();
    for (unsigned int posDiapo = 0; posDiapo < taille_diaporamas; posDiapo++)
    {
        m->getDiaporamas()[posDiapo]->triCroissantRang();
    }

    p->setModele(m);
    p->setVue(&w);

    p->initialize();
    w.connect(p);

    w.setWindowTitle("Lecteur de diaporama - V4 (MVP)");
    w.setWindowIcon(QIcon(":/icon"));

    w.show();

    return a.exec();
}
