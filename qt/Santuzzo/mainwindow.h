#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNuova_partita_triggered();
    void bottone_acceso();
    void bottone_spento();
    void mostra_colore();
    void nascondi_colore();
    void mossa();
    void inizia_turno();

private:
    void accendi(const QString& nome);
    void spegni(const QString& nome);
    QList<QString> m_colori;
    int m_mossa;
    bool in_mostra_colori;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
