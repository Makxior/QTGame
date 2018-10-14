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
    Weapon Allweapons[20];
    int GoldBalance{0};

private slots:

    void on_ListOfitems_doubleClicked(const QModelIndex &index);
    void UploadResources();
    void LoadWepons();
    void UploadStats();
    void AddWeaponsStats(const Weapon& WP);

    void on_exit_clicked();

    void on_exit_2_clicked();

private:
    Ui::armory *ui;
    QVector<Weapon>WeaponsInArmory;
    int LvlInArmory;
    int AttackInArmory;
    int DefInArmory;
    int HpInArmory;
};

#endif // ARMORY_H
