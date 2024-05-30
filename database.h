#ifndef DATABASE_H
#define DATABASE_H

#define DSN "lespiet_bd"
#define DRIVER "QODBC"

#include <QSqlDatabase>
#include "image.h"

class Lecteur;
class Database
{
public:
    Database();

    bool openDatabase();
    void closeDatabase();

    void importImages(Images&) const;
    void importDiapos(Lecteur*, Images&) const;

    bool isOpen() const;

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
