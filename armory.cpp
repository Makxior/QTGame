#include "armory.h"
#include "ui_armory.h"


armory::armory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::armory)
{
    ui->setupUi(this);
}

armory::~armory()
{
    delete ui;
}
void armory::Start(int gold, int lvl,QVector<Weapon> weapons,int atack,int def,int hp)
{
    AmountOfGold = gold;
    WeaponsInArmory = weapons;
    LvlInArmory = lvl;
    AttackInArmory = atack;
    DefInArmory = def;
    HpInArmory = hp;
    LoadWepons();
    UploadResources();
    UploadStats();
    for(int i=0; i<weapons.size();i++)
    {
        if(weapons[i].equipped == true)
        {
            ui->ListOfitems->item(weapons[i].Id)->setTextColor("blue");
        }
    }
    QDialog::exec();
}
void armory::LoadWepons()
{
    Allweapons[0] = Weapon{0,0,5,5,30,1,1,false}; //drewniany miecz
    Allweapons[1] = Weapon{1,0,10,5,50,1,1,false}; //kamienny miecz
    Allweapons[2] = Weapon{2,0,20,5,100,1,2,false}; //złoty miecz

            /*int Id{0};
            int BonusHp{0}; 100
            int BonusAttack{0}; 10
            int BonusDef{0}; 10
            int Cost{0};
            int WhichSlot{0};
            int LvlNeeded{0};*/
}
void armory::on_ListOfitems_doubleClicked(const QModelIndex &index)
{
    QMessageBox msgBox;
    bool have{true};
    if((Allweapons[index.row()].LvlNeeded <= LvlInArmory) && (Allweapons[index.row()].Cost<=AmountOfGold))
    {
        for(Weapon i:WeaponsInArmory)
        {
             if(i.WhichSlot == Allweapons[index.row()].WhichSlot)
             {
                 msgBox.setText("U already got a weapon on this slot");
                 msgBox.exec();
                 have=false;
             }
        }
        if(have)
        {
            AmountOfGold -=Allweapons[index.row()].Cost;
            GoldBalance -=Allweapons[index.row()].Cost;
            UploadResources();
            Allweapons[index.row()].equipped=true;
            WeaponsInArmory.append(Allweapons[index.row()]);
            ui->ListOfitems->item(index.row())->setTextColor("blue");
         }
    }
    else
    {
        msgBox.setText("You dont have enough gold or your lvl is to low");
        msgBox.exec();
    }
    UploadStats();
}
void armory::UploadResources()
{
    ui->AmountOfGold->setText("GOLD : " + QString::number(AmountOfGold));
}
void armory::UploadStats()
{
    HpInArmory=100;
    AttackInArmory=10;
    DefInArmory=10;
    for(auto i:WeaponsInArmory)
    {
        AddWeaponsStats(i);
    }
    ui->AmountOfHp->setText("Health : " + QString::number(HpInArmory));
    ui->AmountOfAttack->setText("Attack : " + QString::number(AttackInArmory));
    ui->AmountOfDef->setText("Defens : " + QString::number(DefInArmory));
    ui->AmountOfLevel->setText("Level : " + QString::number(LvlInArmory));
}
void armory::AddWeaponsStats(const Weapon& WP)
{
    HpInArmory+=WP.BonusHp;
    AttackInArmory+=WP.BonusAttack;
    DefInArmory+=WP.BonusDef;
}

void armory::on_exit_clicked()
{
    this->close();
}

void armory::on_exit_2_clicked()
{

}
