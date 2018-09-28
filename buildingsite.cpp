#include "buildingsite.h"
#include "ui_buildingsite.h"
#include "thegame.h"

BuildingSite::BuildingSite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuildingSite)
{
    ui->setupUi(this);
}

BuildingSite::~BuildingSite()
{
    delete ui;
}
void BuildingSite::Start(int W,int S,int G,bool SB,bool QB,bool WBB,bool SBB,bool GBB,bool MB)
{
    AmountOfWood = W;
    AmountOfStone = S;
    AmountOfGold = G;
    ui->AmountOfWood->setText("WOOD  : " + QString::number(AmountOfWood));
    ui->AmountOfStone->setText("STONE : " + QString::number(AmountOfStone));
    ui->AmountOfGold->setText("WOOD  : " + QString::number(AmountOfGold));
    SawmillBuilt =SB;
    QuarryBuilt = QB;
    WoodBoostBuilt = WBB;
    StoneBoostBuilt = SBB;
    GoldBoostBuilt = GBB;
    Marketbuilt = MB;
    QDialog::exec();
}

void BuildingSite::on_exit_clicked()
{
    this->close();
}

void BuildingSite::on_BuildWoodBoost_clicked()
{
    QMessageBox msgBox;
    if(AmountOfStone>= 20 && AmountOfWood >= 100)
    {
    msgBox.setText("WOOD BOOSTED");
    WoodBoostBuilt = true;
    AmountOfStone-=20;
    AmountOfWood-=100;
    UploadResources();
    WoodSpent +=100;
    StoneSpent +=20;
    ui->BuildWoodBoost->setVisible(false);
    ui->label_woodboost->setVisible(false);
    ui->WoodBoost->setPixmap(QPixmap(":/images/Imgs/WoodBoost.png"));
    msgBox.exec();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void BuildingSite::on_Buildsawmill_clicked()
{
    QMessageBox msgBox;
    if(AmountOfStone>= 50 && AmountOfWood >= 50)
    {
        msgBox.setText("Sawmill have been built");
        AmountOfStone-=50;
        AmountOfWood-=50;
        SawmillBuilt = true;
        WoodSpent +=50;
        StoneSpent +=50;
        UploadResources();
        msgBox.exec();
        ui->Buildsawmill->setVisible(false);
        ui->label_Sawmill->setVisible(false);
        ui->Sawmill->setPixmap(QPixmap(":/images/Imgs/samwill.png"));
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}
void BuildingSite::UploadResources()
{
    ui->AmountOfStone->setText("STONE : " + QString::number(AmountOfStone));
     ui->AmountOfWood->setText("WOOD  : "  + QString::number(AmountOfWood));
     ui->AmountOfGold->setText("GOLD  : "  + QString::number(AmountOfGold));
}

void BuildingSite::on_BuildQuarry_clicked()
{
    QMessageBox msgBox;
    if(AmountOfStone>= 50 && AmountOfWood >= 50)
    {
        msgBox.setText("Quarry have been built");
        msgBox.exec();
        AmountOfStone-=50;
        AmountOfWood-=50;
        QuarryBuilt = true;
        WoodSpent +=50;
        StoneSpent +=50;
        UploadResources();
        ui->BuildQuarry->setVisible(false);
        ui->label_Quarry->setVisible(false);
        ui->Quarry->setPixmap(QPixmap(":/images/Imgs/Quarry.png"));
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void BuildingSite::on_BuildMarket_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Comming soon");
    msgBox.exec();
}

void BuildingSite::on_BuildStoneBoost_clicked()
{
    QMessageBox msgBox;
    if(AmountOfStone>= 100 && AmountOfWood >= 20)
    {
    msgBox.setText("STONE BOOSTED");
    StoneBoostBuilt = true;
    AmountOfStone-=100;
    AmountOfWood-=20;
    UploadResources();
    WoodSpent +=20;
    StoneSpent +=100;
    ui->BuildStoneBoost->setVisible(false);
    ui->label_stoneboost->setVisible(false);
    ui->StoneBoost->setPixmap(QPixmap(":/images/Imgs/stoneboost.png"));
    msgBox.exec();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void BuildingSite::on_BuildGoldBoost_clicked()
{
    QMessageBox msgBox;
    if(AmountOfStone>= 200 && AmountOfWood >= 200)
    {
    msgBox.setText("GOLD BOOSTED");
    GoldBoostBuilt = true;
    AmountOfStone-=200;
    AmountOfWood-=200;
    UploadResources();
    WoodSpent +=200;
    StoneSpent +=200;
    ui->BuildGoldBoost->setVisible(false);
    ui->label_goldboost->setVisible(false);
    ui->GoldBoost->setPixmap(QPixmap(":/images/Imgs/gooldboost.png"));
    msgBox.exec();
    }
    else
    {
        msgBox.setText("Need more resources");
        msgBox.exec();
    }
}

void BuildingSite::on_pushButton_clicked()
{
    if(Marketbuilt)
    {
        ;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Market is not built");
        msgBox.exec();
    }
}
