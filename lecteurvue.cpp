#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <iostream>
#include <QDebug>
#include <QPixmap>

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::connect(QObject *c)
{
    QObject::connect(ui->nextBtn, SIGNAL(clicked()), c, SLOT(nextImage()));
    QObject::connect(ui->modeBtn, SIGNAL(clicked()), c, SLOT(received()));
    QObject::connect(ui->previousBtn, SIGNAL(clicked()), c, SLOT(previousImage()));

    QObject::connect(ui->actionAutomatique_2, SIGNAL(triggered()), c, SLOT(received()));
    QObject::connect(ui->actionManuel_2, SIGNAL(triggered()), c, SLOT(received()));
    QObject::connect(ui->actionPersonnalis, SIGNAL(triggered()), c, SLOT(received()));
    QObject::connect(ui->action1_seconde, SIGNAL(triggered()), c, SLOT(received()));
    QObject::connect(ui->action5_secondes, SIGNAL(triggered()), c, SLOT(received()));
    QObject::connect(ui->action10_secondes, SIGNAL(triggered()), c, SLOT(received()));
    QObject::connect(ui->actionCharger_un_diaporama, SIGNAL(triggered()), c, SLOT(received()));
    QObject::connect(ui->actionEnlever_le_diaporama, SIGNAL(triggered()), c, SLOT(received()));

    QObject::connect(ui->actionA_propos, SIGNAL(triggered()), c, SLOT(received()));

    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
}

void LecteurVue::disconnect(QObject *c)
{
    QObject::disconnect(ui->nextBtn, SIGNAL(clicked()), c, SLOT(nextImage()));
    QObject::disconnect(ui->modeBtn, SIGNAL(clicked()), c, SLOT(received()));
    QObject::disconnect(ui->previousBtn, SIGNAL(clicked()), c, SLOT(previousImage()));

    QObject::disconnect(ui->actionAutomatique_2, SIGNAL(triggered()), c, SLOT(received()));
    QObject::disconnect(ui->actionManuel_2, SIGNAL(triggered()), c, SLOT(received()));
    QObject::disconnect(ui->actionPersonnalis, SIGNAL(triggered()), c, SLOT(received()));
    QObject::disconnect(ui->action1_seconde, SIGNAL(triggered()), c, SLOT(received()));
    QObject::disconnect(ui->action5_secondes, SIGNAL(triggered()), c, SLOT(received()));
    QObject::disconnect(ui->action10_secondes, SIGNAL(triggered()), c, SLOT(received()));
    QObject::disconnect(ui->actionCharger_un_diaporama, SIGNAL(triggered()), c, SLOT(received()));
    QObject::disconnect(ui->actionEnlever_le_diaporama, SIGNAL(triggered()), c, SLOT(received()));

    QObject::disconnect(ui->actionA_propos, SIGNAL(triggered()), c, SLOT(received()));

    QObject::disconnect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
}

void LecteurVue::updateDiaporama(QString name, int totalImages)
{
    this->ui->diapoTitle->setText(name);
    this->ui->totalImages->setText(QString::number(totalImages));
    this->ui->diapoProgress->setMaximum(totalImages);
}

void LecteurVue::updateImage(QString name, QString categorie, int current, QString location)
{
    this->ui->currentImage->setText(QString::number(current));
    this->ui->imageName->setText(name);
    this->ui->imageCat->setText(categorie);
    this->ui->image->setPixmap(QPixmap(location));
    this->ui->diapoProgress->setValue(current);
}

