#include "thegame.h"
#include "orccamp.h"
#include "hills.h"
#include "forest.h"
#include "buildingsite.h"
#include "armory.h"
#include "ui_thegame.h"
#include <QVector>

TheGame::TheGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheGame)
{
    ui->setupUi(this);
    //Player start position settings
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));

    Whichplayer = qrand() % (2) + 1;
    if(Whichplayer == 1) ui->player->setPixmap(QPixmap(":/player/Imgs/Player1R.png"));
    if(Whichplayer == 2) ui->player->setPixmap(QPixmap(":/player/Imgs/Player2R.png"));

    connect(sawmillTimer, SIGNAL(timeout()), this, SLOT(Sawmill()));
    ui->SawmillIcon->setVisible(false);

    connect(quarryTimer, SIGNAL(timeout()), this, SLOT(Quarry()));
    ui->QuarryIcon->setVisible(false);

    ui->WoodboostIcon->setVisible(false);
    ui->StoneboostIcon->setVisible(false);
    ui->GoldboostIcon->setVisible(false);

    UploadResources();
    UploadStats();
}
bool kolizja(QFrame* first, QFrame* second)
{
    if( first->x()+first->width() >= second->x()+10 && first->x() <= second->x()+second->width()-10 &&
            first->y()+first->height() >= second->y()+10 && first->y() <= second->y()+second->height()-10)
        return true;
    else return false;
}
void TheGame::Sawmill()
{
    resources.wood++;
    UploadResources();
}

void TheGame::Quarry()
{
    int LuckyCut = qrand() % (10) + 1;;
    if(LuckyCut == 10)
    {
        resources.gold++;
        UploadResources();
    }
    else
    {
        resources.stone++;
        UploadResources();
    }
}
void TheGame::EnterOrcCamp()
{
    OrcCamp orccamp;
    orccamp.Start(resources.gold,soldier);

    UploadStats();
}
void TheGame::LeaveASite()
{
    if(SawmillBuilt){
        sawmillTimer->start(2000);
        ui->SawmillIcon->setVisible(true);
    }
    if(QuarryBuilt){
        quarryTimer->start(2000);
        ui->QuarryIcon->setVisible(true);
    }
    if(WoodBoostBuilt){
        HowMuchWood=3;
        ui->WoodboostIcon->setVisible(true);
    }
    if(StoneBoostBuilt){
        HowMuchStone=3;
        ui->StoneboostIcon->setVisible(true);
    }
    if(GoldBoostBuilt){
        HowMuchGold=2;
        ChanceForGold =2;
        ui->GoldboostIcon->setVisible(true);
    }
}
void TheGame::Building()
{
    BuildingSite buildingsite;
    buildingsite.Start(resources.wood,resources.stone,resources.gold,SawmillBuilt,QuarryBuilt,WoodBoostBuilt,StoneBoostBuilt,GoldBoostBuilt,Marketbuilt);

    SawmillBuilt =buildingsite.SawmillBuilt;
    QuarryBuilt = buildingsite.QuarryBuilt;
    WoodBoostBuilt = buildingsite.WoodBoostBuilt;
    StoneBoostBuilt = buildingsite.StoneBoostBuilt;
    GoldBoostBuilt = buildingsite.GoldBoostBuilt;
    Marketbuilt = buildingsite.Marketbuilt;

    resources.wood +=buildingsite.WoodBalance;
    buildingsite.WoodBalance=0;
    resources.stone +=buildingsite.StoneBalance;
    buildingsite.StoneBalance=0;
    resources.gold+=buildingsite.GoldBalance;
    buildingsite.GoldBalance=0;
    LeaveASite();
}
void TheGame::Armory()
{
    armory armory;
    armory.Start(resources.gold,soldier.Level,soldier.weapons,soldier.Attack,soldier.Def,soldier.Hp);
    soldier.weapons=armory.WeaponsInArmory;
    resources.gold+=armory.GoldBalance;
    armory.GoldBalance=0;
    UploadStats();
}
void TheGame::GettingWood()
{
    static Forest forest;
    forest.Start(HowMuchWood);
    resources.wood+=forest.NumberOfWood;
    forest.NumberOfWood=0;
}
void TheGame::GettingStone()
{
    static Hills hills;
    hills.Start(HowMuchStone,HowMuchGold,ChanceForGold);

    resources.stone += hills.NumberOfStone;
    resources.gold += hills.NumberOfGold;
    hills.NumberOfGold=0;
    hills.NumberOfStone=0;
}
void TheGame::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        Move(ui->player, -24,0);
        if(Whichplayer==1) ui->player->setPixmap(QPixmap(":/player/Imgs/Player1L.png"));
        if(Whichplayer==2) ui->player->setPixmap(QPixmap(":/player/Imgs/Player2L.png"));
    }
    else if (event->key() == Qt::Key_Right){
        Move(ui->player, 24,0);
        if(Whichplayer==1) ui->player->setPixmap(QPixmap(":/player/Imgs/Player1R.png"));
        if(Whichplayer==2) ui->player->setPixmap(QPixmap(":/player/Imgs/Player2R.png"));
    }
    else if (event->key() == Qt::Key_Up){
        Move(ui->player, 0,-24);
    }
    else if (event->key() == Qt::Key_Down){
        Move(ui->player, 0,24);
    }
}
TheGame::~TheGame()
{
    delete ui;
}
void TheGame::on_actionNew_triggered()
{
    resources.wood =0;
    resources.stone =0;
    resources.gold =0;
    ui->player->move(300,240);
    UploadResources();
}
void TheGame::on_actionLoad_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Load Game"), "",
                                                    tr("Game (*.txt);;All Files (*)"));
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        int tempX,tempY,booltemp;
        QTextStream stream( &file );
        stream >>resources.wood;
        stream >>resources.stone;
        stream >>resources.gold;
        UploadResources();
        stream>>tempX>>tempY;
        ui->player->move(tempX,tempY);
        stream >>booltemp;
        SawmillBuilt=booltemp;
        stream >>booltemp;
        QuarryBuilt=booltemp;
        stream >>booltemp;
        WoodBoostBuilt=booltemp;
        stream >>booltemp;
        StoneBoostBuilt=booltemp;
        stream >>booltemp;
        GoldBoostBuilt=booltemp;
        stream >>booltemp;
        Marketbuilt=booltemp;
        int size;
        stream>>size;
        int Id;
        for(int i =0; i<size;i++)
        {
            stream>>Id;
            soldier.weapons.append(Weapon{Id,Allweapons[Id].BonusHp,
                                          Allweapons[Id].BonusAttack,
                                          Allweapons[Id].BonusDef,
                                          Allweapons[Id].Cost,
                                          Allweapons[Id].WhichSlot,
                                          Allweapons[Id].LvlNeeded,
                                          true});//TUTAJ
        }
        LeaveASite();
        UploadStats();
    }
}
void TheGame::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Game"), "",
                                                    tr("Game (*.txt);;All Files (*)"));
    QFile file( fileName );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << resources.wood<<" "<<resources.stone<<" "<<resources.gold<<" "<<ui->player->x()<<" "<<ui->player->y()<<" ";
        stream << SawmillBuilt<<" "<<QuarryBuilt<<" "<<WoodBoostBuilt<<" "<<StoneBoostBuilt<<" "<<GoldBoostBuilt<<" "<<Marketbuilt;
        stream <<" "<<soldier.weapons.size()<<" ";
        for(Weapon i:soldier.weapons)
        {
            stream<<i.Id<<" ";
        }
    }
}
void TheGame::on_actionExit_triggered()
{
    this->close();
}

void TheGame::Move(QLabel* player, int dir, int dir2)
{
    player->move(player->x()+dir,player->y()+dir2);
    if(kolizja(player,ui->forest))
    {
        player->move(player->x()-dir,player->y()-dir2);
        GettingWood();
    }
    if(kolizja(player,ui->quarry))
    {
        player->move(player->x()-dir,player->y()-dir2);
        GettingStone();
    }
    if(kolizja(player,ui->buildingSite))
    {
        player->move(player->x()-dir,player->y()-dir2);
        Building();
    }
    if(kolizja(player,ui->ResourcesTable))
    {
        player->move(player->x()-dir,player->y()-dir2);
    }
    if(kolizja(player,ui->StatsTable))
    {
        player->move(player->x()-dir,player->y()-dir2);
    }
    if(kolizja(player,ui->armory))
    {
        player->move(player->x()-dir,player->y()-dir2);
        Armory();
    }
    if(kolizja(player,ui->OrcCamp))
    {
        player->move(player->x()-dir,player->y()-dir2);
        EnterOrcCamp();
    }
    UploadResources();
}
void TheGame::UploadResources()
{
    ui->AmountOfStone->setText("STONE : " + QString::number(resources.stone));
    ui->AmountOfWood->setText("WOOD : " + QString::number(resources.wood));
    ui->AmountOfGold->setText("GOLD : " + QString::number(resources.gold));
}
void TheGame::UploadStats()
{
    soldier.Hp=100;
    soldier.Attack=10;
    soldier.Def=10;
    for(auto i:soldier.weapons)
    {
        AddWeaponsStats(i);
    }
    ui->AmountOfHp->setText("Health : " + QString::number(soldier.Hp));
    ui->AmountOfAttack->setText("Attack : " + QString::number(soldier.Attack));
    ui->AmountOfDef->setText("Defens : " + QString::number(soldier.Def));
    ui->AmountOfLevel->setText("Level : " + QString::number(soldier.Level));
}
void TheGame::AddWeaponsStats(const Weapon& WP)
{
    soldier.Hp+=WP.BonusHp;
    soldier.Attack+=WP.BonusAttack;
    soldier.Def+=WP.BonusDef;
}

void Soldier::LoadWeapon(Soldier sol, std::fstream &str)
{
    int Id,Atack,HP,Def,Slot;
    str>>Id>>Atack>>HP>>Def>>Slot;
    sol.weapons.append(Weapon{Id,Atack,HP,Def,Slot,0});
}


