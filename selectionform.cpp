#include "selectionform.h"
#include "ui_selectionform.h"

SelectionForm::SelectionForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectionForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Sélectionnez un diaporama");
}

SelectionForm::~SelectionForm()
{
    delete ui;
}

void SelectionForm::setDiaporamaList(Diaporamas diapos)
{
    unsigned int nbDiaporamas = diapos.size();

    for (unsigned int num = 0; num < nbDiaporamas; num++)
    {
        this->ui->comboBox->addItem(diapos[num]->getTitre());
    }
}

int SelectionForm::getSelectedDiaporama() const
{
    return this->ui->comboBox->currentIndex();
}
