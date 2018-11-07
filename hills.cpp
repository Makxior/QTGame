#include "hills.h"
#include "ui_hills.h"
#include <QSound>
#include <QTimer>

Hills::Hills(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hills)
{
    ui->setupUi(this);
}
void Hills::Start(int HowMuchStone, int Gold,int Chance)
{
    HowMuchOnHit = HowMuchStone;
    HowMuchGold = Gold;
    ChanceForGold = Chance;

    QTimer *Grow = new QTimer(this);
    QTimer *unlock = new QTimer(this);

    connect(Grow, SIGNAL(timeout()), this, SLOT(GrowARock()));
    Grow->start(3000);

    connect(unlock, SIGNAL(timeout()), this, SLOT(Unlock()));
    unlock->start(1500);

    QDialog::exec();
}
 void Hills::Unlock()
 {
    ui->pushButton->setVisible(true);
 }
Hills::~Hills()
{
    delete ui;
}
void Hills::CutARock()
{
    int LuckyCut = qrand() % (10) + 1;;
    if(LuckyCut <= ChanceForGold)
    {
        QSound::play(":/Sounds/Sounds/Gold.wav");
        NumberOfGold+=HowMuchGold;
    }
    else
        {
        if(NumberOfRocks == 5 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock_5->setVisible(false);
            NumberOfStone+=HowMuchOnHit;
            NumberOfRocks--;
        }
        else if(NumberOfRocks ==4 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock_4->setVisible(false);
            NumberOfStone+=HowMuchOnHit;
            NumberOfRocks--;
        }
        else if(NumberOfRocks ==3 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock_3->setVisible(false);
            NumberOfStone+=HowMuchOnHit;
            NumberOfRocks--;
        }
        else if(NumberOfRocks ==2 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock_2->setVisible(false);
            NumberOfStone+=HowMuchOnHit;
            NumberOfRocks--;
        }
        else if(NumberOfRocks == 1 )
        {
            QSound::play(":/Sounds/Sounds/Quarry.wav");
            ui->rock->setVisible(false);
            NumberOfStone+=HowMuchOnHit;
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
void Hills::GrowARock()
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
void Hills::on_exit_clicked()
{
    ui->HowManyStone->setText("0");
    ui->HowManyGold->setText("0");
    this->close();
}

void Hills::on_pushButton_clicked()
{
    CutARock();
    ui->pushButton->setVisible(false);
}
