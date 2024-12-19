#ifndef DIALOGCONFIGURAZIONE_H
#define DIALOGCONFIGURAZIONE_H

#include <QDialog>

namespace Ui {
class DialogConfigurazione;
}

class DialogConfigurazione : public QDialog {
    Q_OBJECT

public:
    explicit DialogConfigurazione(int livello, QWidget *parent = nullptr);
    ~DialogConfigurazione();
    int livello() const;

private slots:
    void on_sliderDifficolta_valueChanged(int value);

private:
    int m_livello;
    Ui::DialogConfigurazione *ui;
};

#endif // DIALOGCONFIGURAZIONE_H
