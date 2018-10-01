#include "market.h"
#include "ui_market.h"
#include "thegame.h"

Market::Market(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    ui->setupUi(this);
}

Market::~Market()
{
    delete ui;
}
void Market::Start(int wood, int stone, int gold)
{
    AmountOfWood = wood;
    AmountOfStone = stone;
    AmountOfGold = gold;
    ui->AmountOfWood->setText("WOOD  : " + QString::number(AmountOfWood));
    ui->AmountOfStone->setText("STONE : " + QString::number(AmountOfStone));
    ui->AmountOfGold->setText("WOOD  : " + QString::number(AmountOfGold));

    QDialog::exec();
}
void Market::on_ExchangeWoodForGold_clicked()
{
    QMessageBox msgBox;
    if(AmountOfWood>=10)
    {
        AmountOfWood-=10;
        AmountOfGold+=1;
        WoodExchanged -=10;
        GoldExchanged +=1;
        UploadResources();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void Market::on_exit_clicked()
{
    this->close();
}
void Market::UploadResources()
{
    ui->AmountOfStone->setText("STONE : " + QString::number(AmountOfStone));
     ui->AmountOfWood->setText("WOOD  : "  + QString::number(AmountOfWood));
     ui->AmountOfGold->setText("GOLD  : "  + QString::number(AmountOfGold));
}

void Market::on_ExchangeStoneForWood_clicked()
{
    QMessageBox msgBox;
    if(AmountOfStone>=5)
    {
        AmountOfStone-=5;
        AmountOfWood+=1;
        StoneExchanged -=5;
        WoodExchanged +=1;
        UploadResources();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void Market::on_ExchangeGoldForWood_clicked()
{
    QMessageBox msgBox;
    if(AmountOfGold>=3)
    {
        AmountOfGold-=3;
        AmountOfWood+=1;
        GoldExchanged -=3;
        WoodExchanged +=1;
        UploadResources();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void Market::on_ExchangeStoneForGold_clicked()
{
    QMessageBox msgBox;
    if(AmountOfStone>=10)
    {
        AmountOfStone-=10;
        AmountOfGold+=1;
        StoneExchanged -=10;
        GoldExchanged +=1;
        UploadResources();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void Market::on_ExchangeGoldForStone_clicked()
{
    QMessageBox msgBox;
    if(AmountOfGold>=3)
    {
        AmountOfGold-=3;
        AmountOfStone+=1;
        GoldExchanged -=3;
        StoneExchanged +=1;
        UploadResources();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void Market::on_ExchangeWoodForStone_clicked()
{
    QMessageBox msgBox;
    if(AmountOfWood>=5)
    {
        AmountOfWood-=5;
        AmountOfStone+=1;
        WoodExchanged -=5;
        StoneExchanged +=1;
        UploadResources();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}
