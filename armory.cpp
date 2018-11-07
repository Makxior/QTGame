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
void armory::Start(int gold, double lvl,QVector<Weapon> weapons,int atack,int def,int hp)
{
    AmountOfGold = gold;
    WeaponsInArmory = weapons;
    LvlInArmory = lvl;
    AttackInArmory = atack;
    DefInArmory = def;
    HpInArmory = hp;
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
void armory::on_ListOfitems_doubleClicked(const QModelIndex &index)
{
        QMessageBox msgBox;
        bool have{true};
        if((AllweaponsInArmory[index.row()].LvlNeeded <= LvlInArmory) && (AllweaponsInArmory[index.row()].Cost<=AmountOfGold))
        {
            for(Weapon i:WeaponsInArmory)
            {
                 if(i.WhichSlot == AllweaponsInArmory[index.row()].WhichSlot)
                 {
                     msgBox.setText("U already got a weapon on this slot");
                     msgBox.exec();
                     have=false;
                 }
            }
            if(have)
            {
                AmountOfGold -=AllweaponsInArmory[index.row()].Cost;
                GoldBalance -=AllweaponsInArmory[index.row()].Cost;
                UploadResources();
                AllweaponsInArmory[index.row()].equipped=true;
                WeaponsInArmory.append(AllweaponsInArmory[index.row()]);
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

void armory::on_SellSword_clicked()
{
    for(int i=0; i<WeaponsInArmory.size();i++)
    {
        if(WeaponsInArmory[i].WhichSlot == 1) // 1= weapon
        {
            QMessageBox msgBox;
            msgBox.setText("You have sold your sword");
            msgBox.exec();
            ui->ListOfitems->item(WeaponsInArmory[i].Id)->setTextColor("black");
            GoldBalance+= ((WeaponsInArmory[i].Cost)/2);
            AmountOfGold += ((WeaponsInArmory[i].Cost)/2);
            WeaponsInArmory.remove(i);
            break;
        }
    }
    UploadStats();
    UploadResources();
}

void armory::on_SellArmor_clicked()
{
    for(int i=0; i<WeaponsInArmory.size();i++)
    {
        if(WeaponsInArmory[i].WhichSlot == 2) // 2 = armor
        {
            QMessageBox msgBox;
            msgBox.setText("You have sold your armor");
            msgBox.exec();
            ui->ListOfitems->item(WeaponsInArmory[i].Id)->setTextColor("black");
            GoldBalance+= ((WeaponsInArmory[i].Cost)/2);
            AmountOfGold += ((WeaponsInArmory[i].Cost)/2);
            WeaponsInArmory.remove(i);
            break;
        }
    }
    UploadStats();
    UploadResources();
}

void armory::on_SellShield_clicked()
{
    for(int i=0; i<WeaponsInArmory.size();i++)
    {
        if(WeaponsInArmory[i].WhichSlot == 3) // 2 = shield
        {
            QMessageBox msgBox;
            msgBox.setText("You have sold your shield");
            msgBox.exec();
            ui->ListOfitems->item(WeaponsInArmory[i].Id)->setTextColor("black");
            GoldBalance+= ((WeaponsInArmory[i].Cost)/2);
            AmountOfGold += ((WeaponsInArmory[i].Cost)/2);
            WeaponsInArmory.remove(i);
            break;
        }
    }
    UploadStats();
    UploadResources();
}
