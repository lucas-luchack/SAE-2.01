#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <iostream>
#include <QDebug>

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    QObject::connect(ui->nextBtn, SIGNAL(clicked()), this, SLOT(received()));
    QObject::connect(ui->modeBtn, SIGNAL(clicked()), this, SLOT(received()));
    QObject::connect(ui->previousBtn, SIGNAL(clicked()), this, SLOT(received()));

    QObject::connect(ui->actionAutomatique_2, SIGNAL(triggered()), this, SLOT(received()));
    QObject::connect(ui->actionManuel_2, SIGNAL(triggered()), this, SLOT(received()));
    QObject::connect(ui->actionPersonnalis, SIGNAL(triggered()), this, SLOT(received()));
    QObject::connect(ui->action1_seconde, SIGNAL(triggered()), this, SLOT(received()));
    QObject::connect(ui->action5_secondes, SIGNAL(triggered()), this, SLOT(received()));
    QObject::connect(ui->action10_secondes, SIGNAL(triggered()), this, SLOT(received()));
    QObject::connect(ui->actionCharger_un_diaporama, SIGNAL(triggered()), this, SLOT(received()));
    QObject::connect(ui->actionEnlever_le_diaporama, SIGNAL(triggered()), this, SLOT(received()));

    QObject::connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(received()));

    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::received()
{
    qDebug() << "Clic";
}
