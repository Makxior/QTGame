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
    int Level{1};
    QVector<Weapon> weapons;
    bool Slots[3];
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
    void AddWeaponsStats(const Weapon& Wp);
    Resources resources{999,999,999};
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
