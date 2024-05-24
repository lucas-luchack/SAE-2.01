#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <iostream>
#include <QString>
#include "lecteur.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LecteurVue;
}
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();

    void connect(QObject*);
    void disconnect(QObject*);

    void updateDiaporama(QString, int);
    void updateImage(QString, QString, int, QString);
    void updateModeButton(ModeLecteur);
    void resetInterface() const;

private:
    Ui::LecteurVue *ui;

    void updateStatusMessage(ModeLecteur);

};
#endif // LECTEURVUE_H
