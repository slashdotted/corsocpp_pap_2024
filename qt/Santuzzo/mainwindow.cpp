#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <random>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Cerco tutti i "figli" di centralWidget di tipo QPushButton
    auto bottoni{ui->centralwidget->findChildren<QPushButton*>()};
    for(auto& b : bottoni) {
        connect(b,SIGNAL(pressed()),this,SLOT(bottone_acceso()));
        connect(b,SIGNAL(released()),this,SLOT(bottone_spento()));
        connect(b,SIGNAL(clicked()),this,SLOT(mossa()));
    }
    m_mossa = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuova_partita_triggered()
{
    m_colori.clear();
    m_mossa = -1;
    inizia_turno();
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
    ++m_mossa;
    if (m_mossa < m_colori.size()) {
        accendi(m_colori.at(m_mossa));
        QTimer::singleShot(500,this, &MainWindow::nascondi_colore);
    }
}

void MainWindow::nascondi_colore()
{
    // Nasconde il colore precedente
    if (m_mossa >= 0) {
        spegni(m_colori.at(m_mossa));
    }
    // Se i colori non sono finiti schedula il prossimo mostra colore
    if (m_mossa < m_colori.size()-1) {
        QTimer::singleShot(500,this, &MainWindow::mostra_colore);
    }
    else {
        // Inizia a giocare il giocatore
        m_mossa = 0;
        ui->statusbar->showMessage("Ripeti la sequenza");
        in_mostra_colori = false;
    }
}

void MainWindow::mossa()
{
    if (!in_mostra_colori) {
        QObject* w{sender()};
        auto nome{w->objectName()};
        if (m_mossa == m_colori.size() -1 && m_colori.at(m_mossa) == nome) {
            ui->statusbar->showMessage("Corretto!");
            in_mostra_colori = true;
            QTimer::singleShot(1500, this, &MainWindow::inizia_turno);
        }
        else if (m_colori.at(m_mossa) != nome) {
            ui->statusbar->showMessage("Peccato!");
            in_mostra_colori = true;
        }
        else {
            ++m_mossa;
        }
    }
}

void MainWindow::accendi(const QString &nome)
{
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/icone/lamp_%1_on.png").arg(nome), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
    auto bottone{ui->centralwidget->findChild<QPushButton*>(nome)};
    if (bottone) {
        bottone->setIcon(icon2);
    }
}

void MainWindow::spegni(const QString &nome)
{
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/icone/lamp_%1_off.png").arg(nome), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
    auto bottone{ui->centralwidget->findChild<QPushButton*>(nome)};
    if (bottone) {
        bottone->setIcon(icon2);
    }
}

void MainWindow::inizia_turno()
{
    // Aggiungi un colore a caso e inizia un nuovo turno
    in_mostra_colori = true;
    QList<QString> colori{"red","green","yellow","blue"};
    std::random_device rd;
    std::mt19937 generator{rd()};
    std::shuffle(colori.begin(), colori.end(), generator);
    auto nuovo{colori.at(0)};
    m_colori.push_back(nuovo);
    m_mossa = -1;
    ui->statusbar->showMessage("Stai attento ai colori");
    QTimer::singleShot(1000,this, &MainWindow::mostra_colore);
}

