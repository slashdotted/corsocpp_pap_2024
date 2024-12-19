#include "dialogconfigurazione.h"
#include "ui_dialogconfigurazione.h"

DialogConfigurazione::DialogConfigurazione(int livello, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogConfigurazione), m_livello{livello}
{
    ui->setupUi(this);
    ui->sliderDifficolta->setValue(livello);
    on_sliderDifficolta_valueChanged(livello);
}

DialogConfigurazione::~DialogConfigurazione()
{
    delete ui;
}

int DialogConfigurazione::livello() const
{
    return m_livello;
}

void DialogConfigurazione::on_sliderDifficolta_valueChanged(int value)
{
    static QString descrizioni[4] {
        "Facile",
        "Complicato (random a inizio partita)",
        "Difficile (random anche a inizio turno)",
        "Estremo (random dopo ogni mossa)"
    };
    m_livello = value;
    ui->descrizione->setText(descrizioni[value-1]);
}

