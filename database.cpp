#include "database.h"
#include <QDebug>

#include <QSqlQuery>

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

void Database::importImages(Lecteur *) const
{

}

void Database::importDiapos(Lecteur *) const
{

}

bool Database::isOpen() const
{
    return this->db.isOpen();
}
