#include "orccamp.h"
#include "ui_orccamp.h"

OrcCamp::OrcCamp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrcCamp)
{
    ui->setupUi(this);
}
void OrcCamp::Start(int gold,Soldier sol)
{
    SoldierInOrcCamp = sol;
    GoldInOrcCamp = gold;
    GoldBalance = 0;

    ui->AmountOfHp->setText("Health : " + QString::number(SoldierInOrcCamp.Hp));
    ui->AmountOfAttack->setText("Attack : " + QString::number(SoldierInOrcCamp.Attack));
    ui->AmountOfDef->setText("Defens : " + QString::number(SoldierInOrcCamp.Def));
    ui->AmountOfLevel->setText("Level : " + QString::number(SoldierInOrcCamp.Level));
    UploadResources();

    QDialog::exec();
}
void OrcCamp::UploadResources()
{
    ui->AmountOfGold->setText("GOLD : " + QString::number(AmountOfGold));
}
OrcCamp::~OrcCamp()
{
    delete ui;
}
