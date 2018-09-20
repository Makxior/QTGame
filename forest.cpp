#include "forest.h"
#include "thegame.h"
#include "ui_forest.h"

Forest::Forest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forest)
{
    ui->setupUi(this);
    {
    ui->tree->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/tree.png"));
    ui->tree_2->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/tree.png"));
    ui->tree_3->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/tree.png"));
    ui->tree_4->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/tree.png"));
    ui->tree_5->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/tree.png"));
    }
}

Forest::~Forest()
{
    delete ui;
}

void Forest::on_pushButton_clicked()
{
    NumberOfWood++;
}

void Forest::on_exit_clicked()
{
    this->close();
}
