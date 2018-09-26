#include "thegame.h"
#include "hills.h"
#include "forest.h"
#include "buildingsite.h"
#include "ui_thegame.h"

TheGame::TheGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheGame)
{
    ui->setupUi(this);
    //Player start position settings
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));

    player = qrand() % ((3 + 1) - 1) + 1;
    if(player == 1) ui->player->setPixmap(QPixmap(":/player/Imgs/player1.png"));
    if(player == 2) ui->player->setPixmap(QPixmap(":/player/Imgs/player2.png"));
    if(player == 3) ui->player->setPixmap(QPixmap(":/player/Imgs/player3.png"));
    connect(sawmillTimer, SIGNAL(timeout()), this, SLOT(Sawmill()));
    ui->SawmillIcon->setVisible(false);
    connect(quarryTimer, SIGNAL(timeout()), this, SLOT(Quarry()));
    ui->QuarryIcon->setVisible(false);

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
}
void TheGame::Building()
{
    static BuildingSite buildingsite;
    buildingsite.Start(resources.wood,resources.stone,resources.gold,SawmillBuilt,QuarryBuilt,WoodBoostBuilt,StoneBoostBuilt,GoldBoostBuilt,Marketbuilt);
    SawmillBuilt =buildingsite.SawmillBuilt;
    QuarryBuilt = buildingsite.QuarryBuilt;
    WoodBoostBuilt = buildingsite.WoodBoostBuilt;
    StoneBoostBuilt = buildingsite.StoneBoostBuilt;
    GoldBoostBuilt = buildingsite.GoldBoostBuilt;
    Marketbuilt = buildingsite.Marketbuilt;
    resources.wood -=buildingsite.WoodSpent;
    buildingsite.WoodSpent=0;
    resources.stone -=buildingsite.StoneSpent;
    buildingsite.StoneSpent=0;
    LeaveASite();
}
void TheGame::GettingWood()
{
    static Forest forest;
    forest.exec();
    resources.wood+=forest.NumberOfWood;
    forest.NumberOfWood=0;
}
void TheGame::GettingStone()
{
    static Hills quarry;
    quarry.exec();
    resources.stone += quarry.NumberOfStone;
    resources.gold += quarry.NumberOfGold;
    quarry.NumberOfGold=0;
    quarry.NumberOfStone=0;
}
void TheGame::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
            Move(ui->player, -24,0);
            if(player==1) ui->player->setPixmap(QPixmap(":/player/Imgs/player12.png"));
            if(player==2) ui->player->setPixmap(QPixmap(":/player/Imgs/player22.png"));
            if(player==3) ui->player->setPixmap(QPixmap(":/player/Imgs/player32.png"));
        }
        else if (event->key() == Qt::Key_Right){
            Move(ui->player, 24,0);
            if(player==1) ui->player->setPixmap(QPixmap(":/player/Imgs/player1.png"));
            if(player==2) ui->player->setPixmap(QPixmap(":/player/Imgs/player2.png"));
            if(player==3) ui->player->setPixmap(QPixmap(":/player/Imgs/player3.png"));
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
        int temp,temp2;
        QTextStream stream( &file );
        stream >>resources.wood;
        stream >>resources.stone;
        stream >>resources.gold;
        UploadResources();
        stream>>temp>>temp2;
        ui->player->move(temp,temp2);
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
        stream << resources.wood<<" "<<resources.stone<<" "<<resources.gold<<" "<<ui->player->x()<<" "<<ui->player->y();
    }
}
void TheGame::Move(QLabel* player, int dir, int dir2)
{
        player->move(player->x()+dir,player->y()+dir2);
        if(kolizja(player,ui->forest))
        {
            player->move(player->x()-dir,player->y()-dir2);
            GettingWood();
            UploadResources();
        }
        if(kolizja(player,ui->quarry))
        {
            player->move(player->x()-dir,player->y()-dir2);
            GettingStone();
            UploadResources();
        }
        if(kolizja(player,ui->buildingSite))
        {
            player->move(player->x()-dir,player->y()-dir2);
            Building();
            UploadResources();
        }
        if(kolizja(player,ui->ResourcesTable))
        {
            player->move(player->x()-dir,player->y()-dir2);
        }
}
void TheGame::UploadResources()
{
    ui->AmountOfStone->setText("STONE : " + QString::number(resources.stone));
    ui->AmountOfWood->setText("WOOD  : " + QString::number(resources.wood));
    ui->AmountOfGold->setText("GOLD  : " + QString::number(resources.gold));
}
