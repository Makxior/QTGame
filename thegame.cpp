#include "thegame.h"
#include "forest.h"
#include "quarry.h"
#include "ui_thegame.h"
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsItem>
#include <QTime>
#include <QSound>

TheGame::TheGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheGame)
{
    ui->setupUi(this);
    //Player start position settings
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    player = qrand() % ((3 + 1) - 1) + 1;
    if(player == 1) ui->player->setPixmap(QPixmap(":/player/Imgs/player1.png"));
    if(player == 2) ui->player->setPixmap(QPixmap(":/player/Imgs/player2.png"));
    if(player == 3) ui->player->setPixmap(QPixmap(":/player/Imgs/player3.png"));

}
bool kolizja(QLabel* first, QLabel* second)
{
  if( first->x() >= second->x()-first->width() && first->x() <= second->x()+second->width() &&
    first->y() >= second->y()-first->height() && first->y() <= second->y()+second->height())
    return true;
    else return false;
}
void TheGame::GettingWood()
{
    Forest forest;
    forest.setModal(true);
    forest.exec();
    wood+=forest.NumberOfWood;
    forest.NumberOfWood =0;
}
void TheGame::GettingStone()
{
    Quarry quarry;
    quarry.setModal(true);
    quarry.exec();
    stone += quarry.NumberOfStone;
    gold += quarry.NumberOfGold;
    quarry.NumberOfStone = 0;
    quarry.NumberOfGold = 0;
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
    wood =0;
    stone =0;
    gold =0;
    ui->player->move(300,240);
    ui->AmountOfStone->setText("STONE : 0");
     ui->AmountOfWood->setText("WOOD  : 0");
     ui->AmountOfGold->setText("GOLD  : 0");
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
        stream >>wood;
        ui->AmountOfWood->setText("WOOD  : " + QString::number(wood));
        stream >>stone;
        ui->AmountOfStone->setText("STONE : " +QString::number(stone));
        stream >>gold;
        ui->AmountOfGold->setText("GOLD  : " + QString::number(gold));
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
        stream << wood<<" "<<stone<<" "<<gold<<" "<<ui->player->x()<<" "<<ui->player->y();
    }
}
void TheGame::Move(QLabel* player, int dir, int dir2)
{
        player->move(player->x()+dir,player->y()+dir2);
        if(kolizja(player,ui->wood))
        {
            player->move(player->x()-dir,player->y()-dir2);
            GettingWood();
            QString s = QString::number(wood);
            ui->AmountOfWood->setText("WOOD  : " + s);
        }
        if(kolizja(player,ui->stone))
        {
            player->move(player->x()-dir,player->y()-dir2);
            GettingStone();
            QString s = QString::number(stone);
            ui->AmountOfStone->setText("STONE : " + s);
            QString s2 = QString::number(gold);
            ui->AmountOfGold->setText("GOLD  : " + s2);
        }
}

