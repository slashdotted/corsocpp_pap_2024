#ifndef GAMEPREFERENCES_H
#define GAMEPREFERENCES_H

#include <QDialog>

namespace Ui {
class GamePreferences;
}

class GamePreferences : public QDialog
{
    Q_OBJECT

public:
    explicit GamePreferences(int livello, QWidget *parent = nullptr);
    ~GamePreferences();
    int difficolta();

private slots:
    void difficoltaChanged(int value);

private:
    int m_difficolta{0};
    Ui::GamePreferences *ui;
};


#endif // GAMEPREFERENCES_H
