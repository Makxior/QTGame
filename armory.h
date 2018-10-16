#ifndef ARMORY_H
#define ARMORY_H

#include <QDialog>
#include <QModelIndex>
#include <QListWidgetItem>
#include <QVector>
#include <QDialog>
#include <thegame.h>


namespace Ui {
class armory;
}

class armory : public QDialog
{
    Q_OBJECT

public:
    explicit armory(QWidget *parent = nullptr);
    ~armory();
    friend void TheGame::Armory();
    void Start(int gold, int lvl,QVector<Weapon> weapons,int atack,int def,int hp);
    int AmountOfGold;
    Weapon AllweaponsInArmory[20]={ Weapon{0,0,5,5,30,1,1,false}, //drewniany miecz
                                    Weapon{1,0,10,5,50,1,1,false}, //kamienny miecz
                                    Weapon{2,0,20,5,100,1,2,false}};//złoty miecz
    int GoldBalance{0};

private slots:

    void on_ListOfitems_doubleClicked(const QModelIndex &index);
    void UploadResources();
    void UploadStats();
    void AddWeaponsStats(const Weapon& WP);

    void on_exit_clicked();

    void on_SellSword_clicked();

    void on_SellArmor_clicked();

    void on_SellShield_clicked();

private:
    Ui::armory *ui;
    QVector<Weapon>WeaponsInArmory;
    int LvlInArmory;
    int AttackInArmory;
    int DefInArmory;
    int HpInArmory;
};

#endif // ARMORY_H
