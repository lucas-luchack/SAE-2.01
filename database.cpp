#include "database.h"
#include <QDebug>

#include <QSqlError>
#include <QSqlQuery>
#include "image.h"
#include "diaporama.h"
#include "lecteur.h"

Database::Database()
{

}

/**
 * Ouvre la base de données
 *
 * @brief Database::openDatabase
 * @return Base de données correctement ouverte ou non
 */
bool Database::openDatabase()
{
    if (this->db.isOpen())
    {
        qDebug() << "DB already opened!";
        return false;
    }
    else
    {
        this->db = QSqlDatabase::addDatabase(DRIVER);
        this->db.setDatabaseName(DSN);
        bool state = this->db.open();

        if (state) {
            qDebug() << "DB successfuly opened!";
            return true;
        }
        else
        {
            qDebug() << "There was an error while opening the DB!" << Qt::endl << "See logs for more informations";
            qDebug() << this->db.lastError().text();
            return false;
        }
    }
}

/**
 * Ferme la base de données
 *
 * @brief Database::closeDatabase
 */
void Database::closeDatabase()
{
    this->db.close();
}

/**
 * Importation des images depuis la base de données vers le lecteur de diaporama
 *
 * @brief Database::importImages
 * @param imgs Stack d'images
 * @return Si oui ou non les images sont correctements importées
 */
bool Database::importImages(Images &imgs) const
{
    if (this->db.isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT i.idphoto, i.titrePhoto, f.nomFamille, i.uriPhoto FROM Diapos i JOIN Familles f ON f.idFamille = i.idFam ORDER BY idphoto");
        Image *imageACharger;

        if (query.exec())
        {
            for (unsigned int i = 0; query.next(); i++)
            {
                imageACharger = new Image(query.value(0).toUInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString());
                imgs.push_back(imageACharger);
            }

            return true;
        }
    }

    return false;
}

/**
 * Importe les diaporamas depuis la base de données vers le lecteur de diaporama
 *
 * @brief Database::importDiapos
 * @param l - Pointeur vers le lecteur
 * @param imgs - Liste des images importées
 * @return Si oui ou non les diaporamas sont correctement importés
 */
bool Database::importDiapos(Lecteur *l, Images &imgs) const
{
    if (this->db.isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM Diaporamas");
        bool ok = query.exec();

        Diaporama *diaporama;

        if (ok)
        {
            for (unsigned int i = 0; query.next(); i++)
            {
                diaporama = new Diaporama(query.value(0).toUInt(), query.value(1).toString(), query.value(2).toUInt() * 1000);

                QSqlQuery query2;
                query2.prepare("SELECT * FROM DiaposDansDiaporama WHERE idDiaporama = :id");
                query2.bindValue(":id", query.value(0).toUInt());
                query2.exec();

                for (unsigned int i = 0; query2.next(); i++)
                {
                    diaporama->ajouterImage(imgs[(query2.value(0).toInt())-1], query2.value(2).toInt());
                }

                l->chargerDiaporama(diaporama);
            }

            return true;
        }
    }

    return false;
}

/**
 * Met à jour la vitesse par défaut du diaporama dans la BDD
 *
 * @brief Database::updateSpeed
 * @param id Id du diaporama a modifier
 * @param vitesse Nouvelle vitesse du diaporama
 * @return Si oui ou non la modification a bien été appliquée
 */
bool Database::updateSpeed(unsigned int id, unsigned int vitesse)
{
    if (this->db.isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE Diaporamas SET vitesseDefilement = :speed WHERE idDiaporama = :id");
        query.bindValue(":speed", vitesse);
        query.bindValue(":id", id);

        if (query.exec())
        {
            return true;
        }
    }

    return false;
}

/**
 * Met à jour l'URI de l'image dans la BDD
 *
 * @brief Database::updateCheminImage
 * @param id Id de l'image à modifier
 * @param uri Nouvelle URI de l'image
 * @return Si oui ou non la modification a bien été appliquée
 */
bool Database::updateCheminImage(unsigned int id, QString uri)
{
    if (this->db.isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE Diapos SET uriPhoto = :text WHERE idphoto = :id");
        query.bindValue(":id", id);
        query.bindValue(":text", uri);

        if (query.exec())
        {
            return true;
        }
    }

    return false;
}

/**
 * Met à jour la catégorie de l'image dans la BDD
 *
 * @brief Database::updateCatImage
 * @param idImg ID de l'image
 * @param idCat ID de la nouvelle catégorie de l'image
 * @return Si oui ou non la modification a bien été appliquée
 */
bool Database::updateCatImage(unsigned int idImg, unsigned int idCat)
{
    if (this->db.isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE Diapos SET idFam = :idC WHERE idphoto = :idP");
        query.bindValue(":idP", idImg);
        query.bindValue(":idC", idCat);

        if (query.exec())
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Database::retrieveAllImagesCat
 * @param name Stack de tout les noms
 * @param id Stack de tout les id
 * @return Si oui ou non la récupération s'est bien passée
 */
bool Database::retrieveAllImagesCat(std::vector<QString> &name, std::vector<unsigned int> &id)
{
    if (this->db.isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM Familles ORDER BY idFamille");

        if (query.exec())
        {
            for (unsigned int i = 0; query.next(); i++)
            {
                name.push_back(query.value(1).toString());
                id.push_back(query.value(0).toUInt());
            }

            return true;
        }
    }

    return false;
}

bool Database::isOpen() const
{
    return this->db.isOpen();
}
