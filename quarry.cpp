#include "quarry.h"
#include "ui_quarry.h"
#include <QSound>
#include <QTimer>

Quarry::Quarry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quarry)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(GrownARock()));
    timer->start(5000);
    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(Unlock()));
    timer2->start(2000);
}

 void Quarry::Unlock()
 {
    ui->pushButton->setVisible(true);
 }
Quarry::~Quarry()
{
    delete ui;
}
void Quarry::CutARock()
{
    int LuckyCut = qrand() % ((10 + 1) - 1) + 1;;
    if(LuckyCut == 10)
    {
        QSound::play(":/Sounds/Sounds/Gold.wav");
        NumberOfGold++;
    }
    else
        {
        if(NumberOfRocks == 5 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock_5->setVisible(false);
            NumberOfStone++;
            NumberOfRocks--;
        }
        else if(NumberOfRocks ==4 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock_4->setVisible(false);
            NumberOfStone++;
            NumberOfRocks--;
        }
        else if(NumberOfRocks ==3 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock_3->setVisible(false);
            NumberOfStone++;
            NumberOfRocks--;
        }
        else if(NumberOfRocks ==2 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock_2->setVisible(false);
            NumberOfStone++;
            NumberOfRocks--;
        }
        else if(NumberOfRocks == 1 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock->setVisible(false);
            NumberOfStone++;
            NumberOfRocks--;
        }
        else if(NumberOfRocks ==0 )
        {
            ;//nothing happens, cant cut three when there are no rocks
        }
    }
    ui->HowManyStone->setText(QString::number(NumberOfStone));
    ui->HowManyGold->setText(QString::number(NumberOfGold));

}
void Quarry::GrownARock()
{
    if(NumberOfRocks == 5 )
    {
        ;//Nothing happens, maximum number of trees on map
    }
    else if(NumberOfRocks ==4 )
    {
        ui->rock_5->setVisible(true);
        NumberOfRocks++;
    }
    else if(NumberOfRocks ==3 )
    {
        ui->rock_4->setVisible(true);
        NumberOfRocks++;
    }
    else if(NumberOfRocks ==2 )
    {
        ui->rock_3->setVisible(true);
        NumberOfRocks++;
    }
    else if(NumberOfRocks == 1 )
    {
        ui->rock_2->setVisible(true);
        NumberOfRocks++;
    }
    else if(NumberOfRocks ==0 )
    {
        ui->rock->setVisible(true);
        NumberOfRocks++;
    }

}
void Quarry::on_exit_clicked()
{
    this->close();
}

void Quarry::on_pushButton_clicked()
{
    CutARock();
    ui->pushButton->setVisible(false);
}
