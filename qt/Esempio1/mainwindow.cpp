#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <string>

static void foo(QPushButton b)
{
    // ...
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dial->setValue(50);
    ui->pushButton->setText("Clicca qui");
    setWindowTitle("Esempio");

    auto pushButton = new QPushButton(ui->centralwidget);
    pushButton->setObjectName("pushButton1");
    pushButton->setText("Bottone nuovo");
    pushButton->setGeometry(QRect(150, 170, 120, 26));
    //foo(*pushButton); // Non posso fare una copia di QObject

    connect(ui->actionApri, SIGNAL(triggered()), this, SLOT(apriFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->dial->setValue(0);
}

void MainWindow::apriFile()
{
    qDebug() << "Apertura file";
    std::string m{"Questa è una stringa"};
    QString q{"Questa è una stringa"};
    qDebug() << "#m = " << m.size() << " #q = " << q.size();
}

