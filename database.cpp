#include "database.h"
#include <QDebug>

#include <QSqlQuery>
#include "image.h"
#include "diaporama.h"
#include "lecteur.h"

Database::Database()
{

}

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
            return false;
        }
    }
}

void Database::closeDatabase()
{
    this->db.close();
}

void Database::importImages(Images &imgs) const
{
    if (this->db.isOpen())
    {
        QSqlQuery query("SELECT i.idphoto, i.titrePhoto, f.nomFamille, i.uriPhoto FROM Diapos i JOIN Familles f ON f.idFamille = i.idFam ORDER BY idphoto;");
        bool ok = query.exec();

        Image *imageACharger;

        if (ok)
        {
            for (unsigned int i = 0; query.next(); i++)
            {
                imageACharger = new Image(query.value(0).toUInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString());
                imgs.push_back(imageACharger);
            }
        }
    }
}

void Database::importDiapos(Lecteur *l, Images &imgs) const
{
    if (this->db.isOpen())
    {
        QSqlQuery query("SELECT * FROM Diaporamas");
        bool ok = query.exec();

        Diaporama *diaporama;

        if (ok)
        {
            for (unsigned int i = 0; query.next(); i++)
            {
                diaporama = new Diaporama(query.value(0).toUInt(), query.value(1).toString(), static_cast<unsigned int>(query.value(2).toInt() * 1000));

                QSqlQuery query2;
                query2.prepare("SELECT * FROM DiaposDansDiaporama WHERE idDiaporama = :id");
                query2.bindValue(":id", query.value(0));

                for (unsigned int i = 0; query2.next(); i++)
                {
                    diaporama->ajouterImage(imgs[query2.value(0).toInt()], query2.value(2).toInt());
                }

                l->chargerDiaporama(diaporama);
            }
        }
    }
}

void Database::updateSpeed(unsigned int id, unsigned int vitesse)
{
    if (this->db.isOpen())
    {

    }
}

void Database::updateImage(unsigned int, ModeModif, QString)
{

}

bool Database::isOpen() const
{
    return this->db.isOpen();
}
