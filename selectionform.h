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
    explicit SelectionForm(QString title, QWidget *parent = nullptr);
    ~SelectionForm();

    void setList(Diaporamas);
    void setList(std::vector<QString>);

    int getSelected() const;

private:
    Ui::SelectionForm *ui;
};

#endif // SELECTIONFORM_H
