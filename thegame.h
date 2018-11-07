#ifndef THEGAME_H
#define THEGAME_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QCloseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsItem>
#include <QTime>
#include <QSound>
#include <QModelIndex>
#include <fstream>
#include <iostream>

struct Weapon
{
    int Id{0};
    int BonusHp{0};
    int BonusAttack{0};
    int BonusDef{0};
    int Cost{0};
    int WhichSlot{0};
    int LvlNeeded{0};
    bool equipped{false};
    Weapon() = default;
    Weapon(const Weapon& wp)= default;
};

struct Resources
{
    int wood;
    int gold ;
    int stone;
};
struct Soldier
{
    int Hp{100};
    int Attack{10};
    int Def{10};
    double Level{1};
    QVector<Weapon> weapons{};
    bool Slots[3];
    Soldier(): Hp(100),Attack(10),Def(10),Level(1),Slots{false}{}
    Soldier(const Soldier& sol)
    {
        this->Hp = sol.Hp;
        this->Attack = sol.Attack;
        this->Def = sol.Def;
        this->Level = sol.Level;
        this->weapons = sol.weapons;
        this->Slots[0] = sol.Slots[0];
        this->Slots[1] = sol.Slots[1];
        this->Slots[2] = sol.Slots[2];
    }
    void LoadWeapon(Soldier sol, std::fstream& str);
};

namespace Ui {
class TheGame;
}

class TheGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheGame(QWidget *parent = nullptr);
    ~TheGame();
    void keyPressEvent(QKeyEvent * event);
    void GettingWood();
    void GettingStone();
    void UploadResources();
    void UploadStats();
    void Building();
    void Armory();
    void EnterOrcCamp();
    void AddWeaponsStats(const Weapon& Wp);
    Resources resources{999,999,999};
    Weapon Allweapons[20]= {
                           Weapon{0,0,5,5,30,1,1,false}, //drewniany miecz
                           Weapon{1,0,10,5,50,1,1,false}, //kamienny miecz
                           Weapon{2,0,20,5,200,1,2,false},//złoty miecz
                           Weapon{3,0,0,10,50,2,1,false},//skorzana zbroja
                           Weapon{4,0,0,20,200,2,3,false},//płytowa zbroja
                           Weapon{5,0,0,40,500,2,5,false},//złota zbroja
                           Weapon{6,0,0,5,25,3,2,false},//skorzana tarcz
                           Weapon{7,0,0,10,50,3,2,false},//drewniana tarcza
                           Weapon{8,0,0,15,100,3,3,false}};//zelazna tarcza
    Soldier soldier;
    QTimer *sawmillTimer = new QTimer(this);
    QTimer *quarryTimer = new QTimer(this);

private slots:

    void on_actionNew_triggered();

    void on_actionLoad_triggered();

    void on_actionSave_triggered();
    void Move(QLabel* player, int dir, int dir2);
    void Sawmill();
    void Quarry();
    void LeaveASite();

    void on_actionExit_triggered();

private:
    bool SawmillBuilt{false},QuarryBuilt{false},WoodBoostBuilt{false},StoneBoostBuilt{false},GoldBoostBuilt{false},Marketbuilt{false};
    int HowMuchWood{1},HowMuchStone{1},HowMuchGold{1},ChanceForGold{1};
    int Whichplayer;
    Ui::TheGame *ui;
};

#endif // THEGAME_H
