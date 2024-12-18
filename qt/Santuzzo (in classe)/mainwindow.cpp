#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <random>
#include <algorithm>
#include "gamepreferences.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(messaggio(QString)), ui->statusbar, SLOT(showMessage(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuova_partita_triggered()
{
    m_colori.clear();
    m_mossa = 0;
    inizio_turno();
}

void MainWindow::bottone_acceso()
{
    QObject* w{sender()};
    auto nome{w->objectName()};
    accendi(nome);
}

void MainWindow::bottone_spento()
{
    QObject* w{sender()};
    auto nome{w->objectName()};
    spegni(nome);
}

void MainWindow::mostra_colore()
{
    accendi(m_colori.at(m_mossa));
    QTimer::singleShot(500,this, &MainWindow::nascondi_colore);
}

void MainWindow::nascondi_colore() {
    spegni(m_colori.at(m_mossa));
    if (m_mossa < m_colori.size()-1) {
        ++m_mossa;
        QTimer::singleShot(500,this, &MainWindow::mostra_colore);
    } else {
        emit messaggio("Ricordi la sequenza corretta?");
        m_mossa = 0;
        if (m_difficolta >= 2) {
            randomizza_bottoni();
        }
        attiva_input_giocatore();
    }
}

void MainWindow::click_giocatore() {
    QObject* w{sender()};
    auto nome{w->objectName()};
    if (nome == m_colori[m_mossa]) {
        ++m_mossa;
        if (m_difficolta >= 3) {
            randomizza_bottoni();
        }
    } else {
        disattiva_input_giocatore();
        emit messaggio("Errore!");
        m_colori.clear();
        QTimer::singleShot(1000,this, &MainWindow::inizio_turno);
        return;
    }
    if (m_mossa == m_colori.size()) {
        disattiva_input_giocatore();
        emit messaggio("Corretto!");
        QTimer::singleShot(1000,this, &MainWindow::inizio_turno);
    }
}

void MainWindow::inizio_turno() {
    disattiva_input_giocatore();
    QList<QString> colori{"red", "green", "yellow", "blue"};
    std::random_device device;
    std::mt19937 generatore{device()};
    std::shuffle(colori.begin(), colori.end(), generatore);
    m_colori.push_back(colori[0]);
    if (m_difficolta >= 1) {
        randomizza_bottoni();
    } else {
        ripristina_bottoni();
    }
    emit messaggio("Stai attento ai colori");
    m_mossa = 0;
    QTimer::singleShot(1000,this, &MainWindow::mostra_colore);
}

void MainWindow::randomizza_bottoni() {
    QList<QString> colori{"red", "green", "yellow", "blue"};
    std::random_device device;
    std::mt19937 generatore{device()};
    std::shuffle(colori.begin(), colori.end(), generatore);
    int i{0};
    auto bottoni{ui->centralwidget->findChildren<QPushButton*>()};
    for(auto& b : bottoni) {
        b->setObjectName(colori[i]);
        spegni(b->objectName());
        ++i;
    }
}

void MainWindow::ripristina_bottoni() {
    QList<QString> colori{"red", "green", "yellow", "blue"};
    int i{0};
    auto bottoni{ui->centralwidget->findChildren<QPushButton*>()};
    for(auto& b : bottoni) {
        b->setObjectName(colori[i]);
        spegni(b->objectName());
        ++i;
    }
}

void MainWindow::attiva_input_giocatore() {
    // Cerco tutti i "figli" di centralWidget di tipo QPushButton
    auto bottoni{ui->centralwidget->findChildren<QPushButton*>()};
    for(auto& b : bottoni) {
        connect(b,SIGNAL(pressed()),this,SLOT(bottone_acceso()));
        connect(b,SIGNAL(released()),this,SLOT(bottone_spento()));
        connect(b,SIGNAL(clicked()),this, SLOT(click_giocatore()));
    }
    ui->actionNuova_partita->setEnabled(true);
    ui->actionPreferenze->setEnabled(true);
}

void MainWindow::disattiva_input_giocatore() {
    // Cerco tutti i "figli" di centralWidget di tipo QPushButton
    auto bottoni{ui->centralwidget->findChildren<QPushButton*>()};
    for(auto& b : bottoni) {
        disconnect(b,SIGNAL(pressed()),this,SLOT(bottone_acceso()));
        disconnect(b,SIGNAL(released()),this,SLOT(bottone_spento()));
        disconnect(b,SIGNAL(clicked()),this, SLOT(click_giocatore()));
    }
    ui->actionNuova_partita->setEnabled(false);
    ui->actionPreferenze->setEnabled(false);
}

void MainWindow::accendi(const QString &nome)
{
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/icone/lamp_%1_on.png").arg(nome), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
    auto bottone{ui->centralwidget->findChild<QPushButton*>(nome)};
    bottone->setIcon(icon2);
}

void MainWindow::spegni(const QString &nome)
{
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/icone/lamp_%1_off.png").arg(nome), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
    auto bottone{ui->centralwidget->findChild<QPushButton*>(nome)};
    bottone->setIcon(icon2);
}

void MainWindow::on_actionPreferenze_triggered() {
    GamePreferences gp{m_difficolta, this};
    gp.show();
    auto result{gp.exec()};
    if (result == QDialog::Accepted) {
        m_difficolta = gp.difficolta();
        qDebug() << "Difficoltà" << m_difficolta;
    } else {
        qDebug() << "Cancel";
    }
}
