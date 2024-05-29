#ifndef DATABASE_H
#define DATABASE_H

#define DSN "lespiet_bd"
#define DRIVER "QODBC"

#include <QSqlDatabase>
#include "lecteur.h"

class Database
{
public:
    Database();

    bool openDatabase();
    void closeDatabase();

    void importImages(Lecteur*) const;
    void importDiapos(Lecteur*) const;

    bool isOpen() const;

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
