#ifndef ORCCAMP_H
#define ORCCAMP_H

#include <QDialog>
#include <thegame.h>

namespace Ui {
class OrcCamp;
}

class OrcCamp : public QDialog
{
    Q_OBJECT

public:
    explicit OrcCamp(QWidget *parent = nullptr);
    ~OrcCamp();
    void Start(int gold,Soldier sol);
    Soldier SoldierInOrcCamp;
    int GoldInOrcCamp;
    int AmountOfGold;
    int GoldBalance{0};
    void UploadResources();
private:
    Ui::OrcCamp *ui;
};

#endif // ORCCAMP_H
