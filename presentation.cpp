#include "presentation.h"

#include <QObject>
#include <QMessageBox>
#include <QTimer>
#include <QInputDialog>
#include "selectionform.h"

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(automaticNext()));

    this->db = new Database();
    this->db->openDatabase();
}

void Presentation::initialize() const
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

void Presentation::nextImage() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->avancer();
        this->updateImage();
        this->changeModeToAuto(false);
    }
}

void Presentation::automaticNext() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->avancer();
        this->updateImage();
    }
}

void Presentation::previousImage() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->modele->getCurrentDiaporama()->reculer();
        this->updateImage();
        this->changeModeToAuto(false);
    }
}

void Presentation::unloadDiapo() const
{
    if (this->modele->getDiaporamasCount() != 0) {
        this->vue->resetInterface();
        this->modele->removeAllDiapo();
        this->timer->stop();
    }
}

void Presentation::loadDiapo() const
{
    SelectionForm selectionDialog("Selectionnez un diaporama", this->vue);
    selectionDialog.setList(this->modele->getDiaporamas());
    int result = selectionDialog.exec();

    if (result == QDialog::Accepted && this->modele->getDiaporamasCount() != 0)
    {
        int selected = selectionDialog.getSelected();
        this->modele->changerDiaporama(selected);
        this->changeModeToManuel(true);
        this->updateDiaporama();
    }
}

void Presentation::loadAllDiapo() const
{
    if(this->modele->getDiaporamasCount()==0)
    {
        Images images;

        bool ok = this->db->importImages(images);
        if (ok)
            ok = this->db->importDiapos(this->modele, images);

        if (ok) {
            unsigned int taille_diaporamas = this->modele->getDiaporamasCount();

            for (unsigned int posDiapo = 0; posDiapo < taille_diaporamas; posDiapo++)
            {
                this->modele->getDiaporamas()[posDiapo]->triCroissantRang();
            }

            this->initialize();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Impossible de charger les données.\nRéessayer plus tard !");
            msgBox.setWindowTitle("Erreur de chargement");
            msgBox.exec();
        }
    }

}



void Presentation::changeMode() const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        if (this->modele->getMode() == ModeLecteur::automatique)
        {
            this->modele->setMode(manuel);
            this->timer->stop();
        }
        else
        {
            this->modele->setMode(automatique);
            this->resetTimerSpeed();
        }

        this->vue->updateModeButton(this->modele->getMode());
    }
}

void Presentation::changeModeToAuto(bool checked) const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        if (checked && this->modele->getMode() != automatique)
        {
            this->modele->setMode(automatique);
            this->resetTimerSpeed();
        }
        else if (!checked && this->modele->getMode() == automatique)
        {
            this->modele->setMode(manuel);
            this->timer->stop();
        }

        this->vue->updateModeButton(this->modele->getMode());
    }
}

void Presentation::changeModeToManuel(bool checked) const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        if (checked && this->modele->getMode() != manuel)
        {
            this->modele->setMode(manuel);
            this->timer->stop();
        }
        else if (!checked && this->modele->getMode() == manuel)
        {
            this->modele->setMode(automatique);
            this->resetTimerSpeed();
        }

        this->vue->updateModeButton(this->modele->getMode());
    }
}

void Presentation::select1SecSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        this->modele->getCurrentDiaporama()->setVitesseDefilement(1000);
        this->resetTimerSpeed();
    }
}

void Presentation::select5SecSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        this->modele->getCurrentDiaporama()->setVitesseDefilement(5000);
        this->resetTimerSpeed();
    }
}

void Presentation::select10SecSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        this->modele->getCurrentDiaporama()->setVitesseDefilement(10000);
        this->resetTimerSpeed();
    }
}

void Presentation::selectOwnSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        bool ok = false;
        double result = QInputDialog::getDouble(this->vue, "Vitesse de défilement", "Entrez la vitesse de défilement en secondes", 1, 0, 50000, 1, &ok);

        if (ok)
        {
            this->modele->getCurrentDiaporama()->setVitesseDefilement(result*1000);
            this->resetTimerSpeed();
        }
    }
}

void Presentation::editDefaultSpeed() const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        bool ok = false;
        double result = QInputDialog::getDouble(this->vue, "Vitesse de défilement", "Entrez la vitesse de défilement en secondes", 1, 0, 50000, 1, &ok);

        if (ok)
        {
            bool ok = this->db->updateSpeed(this->modele->getCurrentDiaporama()->getId(), result);
            this->modele->getCurrentDiaporama()->setVitesseDefilement(result*1000);

            QMessageBox message;
            if (ok)
            {
                message.setWindowTitle("Information");
                message.setIcon(QMessageBox::Information);
                message.setText("Modification effectuée");
                message.exec();
            }
            else
            {
                message.setWindowTitle("Erreur");
                message.setIcon(QMessageBox::Critical);
                message.setText("Une erreur est survenue pendant la modification");
                message.exec();
            }
        }
    }
}

void Presentation::editImageCat() const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        SelectionForm selectionDialog("Selectionnez une catégorie", this->vue);

        std::vector<QString> namesCat;
        std::vector<unsigned int> idCat;
        QMessageBox message;
        bool ok = this->db->retrieveAllImagesCat(namesCat, idCat);

        if (!ok)
        {
            message.setWindowTitle("Erreur");
            message.setIcon(QMessageBox::Critical);
            message.setText("Une erreur est survenue pendant la modification");
            message.exec();
            return;
        }

        selectionDialog.setList(namesCat);
        int result = selectionDialog.exec();

        if (result == QDialog::Accepted)
        {
            int selected = selectionDialog.getSelected() + 1;
            bool ok = this->db->updateCatImage(this->modele->getCurrentDiaporama()->getImage().image->getId(), selected);
            this->modele->getCurrentDiaporama()->getImage().image->setCategorie(namesCat[selected]);

            if (ok)
            {
                message.setWindowTitle("Information");
                message.setIcon(QMessageBox::Information);
                message.setText("Modification effectuée");
                message.exec();
            }
            else
            {
                message.setWindowTitle("Erreur");
                message.setIcon(QMessageBox::Critical);
                message.setText("Une erreur est survenue pendant la modification");
                message.exec();
            }
        }
    }
}

void Presentation::editImageUri() const
{
    if (this->modele->getDiaporamasCount() != 0)
    {
        bool ok = false;
        QString result = QInputDialog::getText(this->vue, "Vitesse de défilement", "Entrez la vitesse de défilement en secondes", QLineEdit::Normal, this->modele->getCurrentDiaporama()->getImage().image->getChemin(), &ok);

        if (ok)
        {
            this->modele->getCurrentDiaporama()->getImage().image->setChemin(result);
            bool ok = this->db->updateCheminImage(this->modele->getCurrentDiaporama()->getImage().image->getId(), result);

            QMessageBox message;
            if (ok)
            {
                message.setWindowTitle("Information");
                message.setIcon(QMessageBox::Information);
                message.setText("Modification effectuée");
                message.exec();
            }
            else
            {
                message.setWindowTitle("Erreur");
                message.setIcon(QMessageBox::Critical);
                message.setText("Une erreur est survenue pendant la modification");
                message.exec();
            }
        }
    }
}

void Presentation::openHelpDialog() const
{
    QMessageBox helpDialog;
    helpDialog.setText("Ce lecteur de diaporama à été réalisé dans le cadre de la SAE 2.02 par trois étudiants de l'IUT de Bayonne et du Pays Basque (département Informatique) :\n\n- ESPIET Lucas\n- RIVRAIS-NOWAKOWSKI Mathis\n- HOARAU Allan");
    helpDialog.setInformativeText("Lecteur de Diaporama / SAE 2.02 / V8-MVP");
    helpDialog.setIcon(QMessageBox::Information);
    helpDialog.exec();
}

void Presentation::updateImage() const
{
    this->vue->updateImage(
                    this->modele->getCurrentDiaporama()->getImage().image->getTitre(),
                    this->modele->getCurrentDiaporama()->getImage().image->getCategorie(),
                    this->modele->getCurrentDiaporama()->getImage().rang,
                    this->modele->getCurrentDiaporama()->getImage().image->getChemin()
                );
}

void Presentation::updateDiaporama() const
{
    this->vue->updateDiaporama(
                    this->modele->getCurrentDiaporama()->getTitre(),
                    this->modele->getCurrentDiaporama()->nbImages()
                );
    
    this->modele->getCurrentDiaporama()->reset();
    this->updateImage();
}

void Presentation::resetTimerSpeed() const
{
    this->timer->stop();
    if (this->modele->getMode() == ModeLecteur::automatique) {
        this->timer->start(this->modele->getCurrentDiaporama()->getVitesseDefilement());
    }
}
