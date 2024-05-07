#include "lecteurvue.h"
#include "lecteur.h"
#include "presentation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LecteurVue w;
    Lecteur *m = new Lecteur;
    Presentation *p = new Presentation;

    p->setModele(m);
    p->setVue(&w);

    w.connect(p);

    w.setWindowTitle("Lecteur de diaporama - V2 (MVP)");
    // w.setWindowIcon(new QIcon());

    w.show();

    return a.exec();
}
