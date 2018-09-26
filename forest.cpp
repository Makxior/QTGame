#include "forest.h"
#include "ui_forest.h"
#include <QSound>

Forest::Forest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forest)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(GrownATree()));
    timer->start(5000);
    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(Unlock()));
    timer2->start(2000);
}

 void Forest::Unlock()
 {
    ui->pushButton->setVisible(true);
 }

Forest::~Forest()
{
    delete ui;
}
void Forest::CutATree()
{
    QSound::play(":/Sounds/Sounds/Forest.wav");
    if(NumberOfTrees == 5 )
    {
        ui->tree_5->setVisible(false);
        NumberOfWood++;
        NumberOfTrees--;
    }
    else if(NumberOfTrees ==4 )
    {
        ui->tree_4->setVisible(false);
        NumberOfWood++;
        NumberOfTrees--;
    }
    else if(NumberOfTrees ==3 )
    {
        ui->tree_3->setVisible(false);
        NumberOfWood++;
        NumberOfTrees--;
    }
    else if(NumberOfTrees ==2 )
    {
        ui->tree_2->setVisible(false);
        NumberOfWood++;
        NumberOfTrees--;
    }
    else if(NumberOfTrees == 1 )
    {
        ui->tree->setVisible(false);
        NumberOfWood++;
        NumberOfTrees--;
    }
    else if(NumberOfTrees ==0 )
    {
        ;//nothing happens, cant cut three when there are no trees
    }

    ui->HowMany->setText(QString::number(NumberOfWood));

}
void Forest::GrownATree()
{
    if(NumberOfTrees == 5 )
    {
        ;//Nothing happens, maximum number of trees on map
    }
    else if(NumberOfTrees ==4 )
    {
        ui->tree_5->setVisible(true);
        NumberOfTrees++;
    }
    else if(NumberOfTrees ==3 )
    {
        ui->tree_4->setVisible(true);
        NumberOfTrees++;
    }
    else if(NumberOfTrees ==2 )
    {
        ui->tree_3->setVisible(true);
        NumberOfTrees++;
    }
    else if(NumberOfTrees == 1 )
    {
        ui->tree_2->setVisible(true);
        NumberOfTrees++;
    }
    else if(NumberOfTrees ==0 )
    {
        ui->tree->setVisible(true);
        NumberOfTrees++;
    }

}
void Forest::on_pushButton_clicked()
{
    CutATree();
    ui->pushButton->setVisible(false);
}

void Forest::on_exit_clicked()
{
    ui->HowMany->setText("0");
    this->close();
}
