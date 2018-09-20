#include "thegame.h"
#include "ui_thegame.h"
#include <forest.h>
#include <quarry.h>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsItem>

//Forest forest;

TheGame::TheGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheGame)
{
    ui->setupUi(this);
    //Player start position settings
}
bool kolizja(QLabel* first, QLabel* second)
{
  if( first->x() >= second->x()-first->width() && first->x() <= second->x()+second->width() &&
    first->y() >= second->y()-first->height() && first->y() <= second->y()+second->height())
    return true;
    else return false;
}
int GettingWood()
{
    Forest forest;
    int temp =0;
    forest.setModal(true);
    forest.exec();
    temp = forest.NumberOfWood;
    forest.NumberOfWood =0;
    return temp;
}
int GettingStone()
{
    Quarry quarry;
    int temp =0;
    quarry.setModal(true);
    quarry.exec();
    temp = quarry.NumberOfStone;
    quarry.NumberOfStone = 0;
    return temp;
}
void TheGame::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
            Move(ui->player, -20,0);
        }
        else if (event->key() == Qt::Key_Right){
            Move(ui->player, 20,0);
        }
        else if (event->key() == Qt::Key_Up){
            Move(ui->player, 0,-20);
        }
        else if (event->key() == Qt::Key_Down){
            Move(ui->player, 0,20);
        }
}

TheGame::~TheGame()
{
    delete ui;
}

void TheGame::on_actionNew_triggered()
{
    //change all values to 0
}

void TheGame::on_actionLoad_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
}

void TheGame::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName();
}
void TheGame::Move(QLabel* player, int dir, int dir2)
{
        player->move(player->x()+dir,player->y()+dir2);
        if(kolizja(player,ui->wood))
        {
            player->move(player->x()-dir,player->y()-dir2);
            wood+=GettingWood();
            QString s = QString::number(wood);
            ui->AmountOfWood->setText("WOOD  : " + s);
        }
        if(kolizja(player,ui->stone))
        {
            player->move(player->x()-dir,player->y()-dir2);
            stone+=GettingStone();
            QString s = QString::number(stone);
            ui->AmountOfStone->setText("STONE : " + s);
        }
}

