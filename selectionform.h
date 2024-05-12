#ifndef SELECTIONFORM_H
#define SELECTIONFORM_H

#include <QDialog>
#include "diaporama.h"

namespace Ui {
class SelectionForm;
}

class SelectionForm : public QDialog
{
    Q_OBJECT

public:
    explicit SelectionForm(QWidget *parent = nullptr);
    ~SelectionForm();

    void setDiaporamaList(Diaporamas);
    int getSelectedDiaporama() const;

private:
    Ui::SelectionForm *ui;
};

#endif // SELECTIONFORM_H
