#ifndef QUARRY_H
#define QUARRY_H

#include <QDialog>
#include <thegame.h>

namespace Ui {
class Quarry;
}

class Quarry : public QDialog
{
    Q_OBJECT

public:
    explicit Quarry(QWidget *parent = nullptr);
    ~Quarry();
    friend void TheGame::GettingStone();

private slots:
    void on_exit_clicked();

    void on_pushButton_clicked();
    void CutARock();
    void GrownARock();
    void Unlock();

private:
    int NumberOfStone=0;
    int NumberOfGold=0;
    int NumberOfRocks =5;
    Ui::Quarry *ui;
};

#endif // QUARRY_H
