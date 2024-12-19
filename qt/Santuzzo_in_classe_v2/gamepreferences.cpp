#include "gamepreferences.h"
#include "ui_gamepreferences.h"

GamePreferences::GamePreferences(int livello, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GamePreferences), m_difficolta{livello}
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(difficoltaChanged(int)));
    ui->horizontalSlider->setSliderPosition(livello);
    difficoltaChanged(livello);
}

GamePreferences::~GamePreferences()
{
    delete ui;
}

int GamePreferences::difficolta() {
    return m_difficolta;
}

void GamePreferences::difficoltaChanged(int value) {
    static QString labels[4] {"Normale",
                            "Difficile (i pulsanti si spostano prima di ripetere i colori)",
                            "Molto difficile (i pulsanti si spostano dopo aver inserito ogni colore)",
                            "Estremamente difficile (i pulsanti si spostano dopo ogni colore)"};
    m_difficolta = value;
    ui->descrizione->setText(labels[value]);
}
