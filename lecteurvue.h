#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <iostream>
#include <QString>

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

private slots:
    void received();

private:
    Ui::LecteurVue *ui;
};
#endif // LECTEURVUE_H
