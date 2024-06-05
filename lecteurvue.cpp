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
    ui->statusBar->showMessage("Mode manuel");
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::connect(QObject *c)
{
    QObject::connect(ui->nextBtn, SIGNAL(clicked()), c, SLOT(nextImage()));
    QObject::connect(ui->modeBtn, SIGNAL(clicked()), c, SLOT(changeMode()));
    QObject::connect(ui->previousBtn, SIGNAL(clicked()), c, SLOT(previousImage()));

    QObject::connect(ui->actionAutomatique_2, SIGNAL(triggered(bool)), c, SLOT(changeModeToAuto(bool)));
    QObject::connect(ui->actionManuel_2, SIGNAL(triggered(bool)), c, SLOT(changeModeToManuel(bool)));
    QObject::connect(ui->actionPersonnalis, SIGNAL(triggered()), c, SLOT(selectOwnSpeed()));
    QObject::connect(ui->action1_seconde, SIGNAL(triggered()), c, SLOT(select1SecSpeed()));
    QObject::connect(ui->action5_secondes, SIGNAL(triggered()), c, SLOT(select5SecSpeed()));
    QObject::connect(ui->action10_secondes, SIGNAL(triggered()), c, SLOT(select10SecSpeed()));
    QObject::connect(ui->actionChanger_un_diaporama, SIGNAL(triggered()), c, SLOT(loadDiapo()));
    QObject::connect(ui->actionCharger_les_diaporamas, SIGNAL(triggered()), c, SLOT(loadAllDiapo()));
    QObject::connect(ui->actionEnlever_les_diaporamas, SIGNAL(triggered()), c, SLOT(unloadDiapo()));
    QObject::connect(ui->actionA_propos, SIGNAL(triggered()), c, SLOT(openHelpDialog()));
    QObject::connect(ui->actionChanger_Cat_image, SIGNAL(triggered()), c, SLOT(editImageCat()));
    QObject::connect(ui->actionChanger_URI_image, SIGNAL(triggered()), c, SLOT(editImageUri()));
    QObject::connect(ui->actionChanger_vitesse_default, SIGNAL(triggered()), c, SLOT(editDefaultSpeed()));

    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
}

void LecteurVue::disconnect(QObject *c)
{
    QObject::disconnect(ui->nextBtn, SIGNAL(clicked()), c, SLOT(nextImage()));
    QObject::disconnect(ui->modeBtn, SIGNAL(clicked()), c, SLOT(received()));
    QObject::disconnect(ui->previousBtn, SIGNAL(clicked()), c, SLOT(previousImage()));

    QObject::disconnect(ui->actionAutomatique_2, SIGNAL(triggered()), c, SLOT(changeModeToAuto(bool)));
    QObject::disconnect(ui->actionManuel_2, SIGNAL(triggered()), c, SLOT(changeModeToManuel(bool)));
    QObject::disconnect(ui->actionPersonnalis, SIGNAL(triggered()), c, SLOT(selectOwnSpeed()));
    QObject::disconnect(ui->action1_seconde, SIGNAL(triggered()), c, SLOT(select1SecSpeed()));
    QObject::disconnect(ui->action5_secondes, SIGNAL(triggered()), c, SLOT(select5SecSpeed()));
    QObject::disconnect(ui->action10_secondes, SIGNAL(triggered()), c, SLOT(select10SecSpeed()));
    QObject::disconnect(ui->actionChanger_un_diaporama, SIGNAL(triggered()), c, SLOT(loadDiapo()));
    QObject::disconnect(ui->actionCharger_les_diaporamas, SIGNAL(triggered()), c, SLOT(loadAllDiapo()));
    QObject::disconnect(ui->actionEnlever_les_diaporamas, SIGNAL(triggered()), c, SLOT(unloadDiapo()));
    QObject::disconnect(ui->actionA_propos, SIGNAL(triggered()), c, SLOT(openHelpDialog()));
    QObject::disconnect(ui->actionChanger_Cat_image, SIGNAL(triggered()), c, SLOT(editImageCat()));
    QObject::disconnect(ui->actionChanger_URI_image, SIGNAL(triggered()), c, SLOT(editImageUri()));
    QObject::disconnect(ui->actionChanger_vitesse_default, SIGNAL(triggered()), c, SLOT(editDefaultSpeed()));

    QObject::disconnect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
}

void LecteurVue::updateDiaporama(QString name, int totalImages)
{
    this->ui->diapoTitle->setText(name);
    this->ui->totalImages->setText(QString::number(totalImages));
    this->ui->diapoProgress->setMaximum(totalImages);
    this->updateStatusMessage(ModeLecteur::manuel);
}

void LecteurVue::updateImage(QString name, QString categorie, int current, QString location)
{
    this->ui->currentImage->setText(QString::number(current));
    this->ui->imageName->setText(name);
    this->ui->imageCat->setText(categorie);
    this->ui->image->setPixmap(QPixmap("C:\\" + location));
    this->ui->diapoProgress->setValue(current);
}

void LecteurVue::updateModeButton(ModeLecteur mode)
{
    QString modeTxt = mode == automatique ? "Arrêter": "Démarrer";
    this->ui->modeBtn->setText(modeTxt);

    this->ui->actionAutomatique_2->setChecked(mode == automatique);
    this->ui->actionManuel_2->setChecked(mode == manuel);
    this->updateStatusMessage(mode);
}

void LecteurVue::resetInterface() const
{
    this->ui->diapoProgress->setValue(0);
    this->ui->diapoTitle->setText("Aucun Diaporama");
    this->ui->imageName->setText("Aucune image");
    this->ui->imageCat->setText("Aucune Catégorie");
    this->ui->currentImage->setText("XX");
    this->ui->totalImages->setText("XX");
    this->ui->image->setText("Aucune image");
    this->ui->modeBtn->setText("Démarrer/Arrêter");
}

void LecteurVue::updateStatusMessage(ModeLecteur mode)
{
    this->ui->statusBar->showMessage(mode == automatique ? "Mode automatique" : "Mode manuel");
}
