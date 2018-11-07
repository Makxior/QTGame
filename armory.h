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
    void Start(int gold, double lvl,QVector<Weapon> weapons,int atack,int def,int hp);
    int AmountOfGold;
    Weapon AllweaponsInArmory[20]= {
                           Weapon{0,0,5,5,30,1,1,false}, //drewniany miecz
                           Weapon{1,0,10,5,50,1,1,false}, //kamienny miecz
                           Weapon{2,0,20,5,200,1,2,false},//złoty miecz
                           Weapon{3,0,0,10,50,2,1,false},//skorzana zbroja
                           Weapon{4,0,0,20,200,2,3,false},//płytowa zbroja
                           Weapon{5,0,0,40,500,2,5,false},//złota zbroja
                           Weapon{6,0,0,5,25,3,2,false},//skorzana tarcz
                           Weapon{7,0,0,10,50,3,2,false},//drewniana tarcza
                           Weapon{8,0,0,15,100,3,3,false}};//zelazna tarcza
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
    double LvlInArmory;
    int AttackInArmory;
    int DefInArmory;
    int HpInArmory;
};

#endif // ARMORY_H
