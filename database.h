#ifndef DATABASE_H
#define DATABASE_H

#define DSN "lespiet_bd"
#define DRIVER "QODBC"

#include <QSqlDatabase>
#include "image.h"

class Lecteur;
class Database
{
enum ModeModif { categorieImg, cheminImg };

public:
    Database();

    bool openDatabase();
    void closeDatabase();

    void importImages(Images&) const;
    void importDiapos(Lecteur*, Images&) const;

    void updateSpeed(unsigned int, unsigned int);
    void updateImage(unsigned int, ModeModif, QString);

    bool isOpen() const;

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
