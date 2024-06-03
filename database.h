#ifndef DATABASE_H
#define DATABASE_H

#define DSN "lespiet_bd"
#define DRIVER "QODBC"

#include <QSqlDatabase>
#include "image.h"

class Lecteur;
class Database
{
enum TypeModif { categorieImg, cheminImg };

public:
    Database();

    bool openDatabase();
    void closeDatabase();

    bool importImages(Images&) const;
    bool importDiapos(Lecteur*, Images&) const;

    bool updateSpeed(unsigned int, unsigned int);
    bool updateCheminImage(unsigned int, QString);
    bool updateCatImage(unsigned int, unsigned int);

    bool retrieveAllImagesCat(std::vector<QString>&, std::vector<unsigned int>&);

    bool isOpen() const;

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
