#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>

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
    }
    m_colori = {"red", "green", "blue", "yellow"};
    m_mossa = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuova_partita_triggered()
{
    ui->statusbar->showMessage("Stai attento ai colori");
    m_mossa = -1;
    QTimer::singleShot(1000,this, &MainWindow::mostra_colore);
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
    if (m_mossa >= 0) {
        spegni(m_colori.at(m_mossa));
    }
    ++m_mossa;
    if (m_mossa < m_colori.size()) {
        accendi(m_colori.at(m_mossa));
        QTimer::singleShot(500,this, &MainWindow::mostra_colore);
    }
    else {
        // Inizia a giocare il giocatore
        ui->statusbar->showMessage("Ripeti la sequenza");
    }
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

