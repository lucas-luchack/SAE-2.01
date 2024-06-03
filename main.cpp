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

    w.setWindowTitle("Lecteur de diaporama - V8 (MVP)");
    w.setWindowIcon(QIcon(":/icon"));

    w.show();

    return a.exec();
}
