#include "selectionform.h"
#include "ui_selectionform.h"

SelectionForm::SelectionForm(QString title, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectionForm)
{
    ui->setupUi(this);
    this->setWindowTitle(title);
}

SelectionForm::~SelectionForm()
{
    delete ui;
}

void SelectionForm::setList(Diaporamas diapos)
{
    unsigned int nbDiaporamas = diapos.size();

    for (unsigned int num = 0; num < nbDiaporamas; num++)
    {
        this->ui->comboBox->addItem(diapos[num]->getTitre());
    }
}

void SelectionForm::setList(std::vector<QString> names)
{
    unsigned int nbVal = names.size();

    for (unsigned int num = 0; num < nbVal; num++)
    {
        this->ui->comboBox->addItem(names[num]);
    }
}

int SelectionForm::getSelected() const
{
    return this->ui->comboBox->currentIndex();
}
