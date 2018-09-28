#ifndef HILLS_H
#define HILLS_H

#include <QDialog>
#include <thegame.h>

namespace Ui {
class Hills;
}

class Hills : public QDialog
{
    Q_OBJECT

public:
    explicit Hills(QWidget *parent = nullptr);
    ~Hills();
    friend void TheGame::GettingStone();

private slots:
    void on_exit_clicked();

    void on_pushButton_clicked();
    void CutARock();
    void GrowARock();
    void Unlock();
    void Start(int HowMuchStone, int Gold,int Chance);

private:
    int NumberOfStone=0;
    int NumberOfGold=0;
    int NumberOfRocks =5;
    int HowMuchOnHit{1},HowMuchGold{1};
    int ChanceForGold{1};
    Ui::Hills *ui;
};

#endif // QUARRY_H
