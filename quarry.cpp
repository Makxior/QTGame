#include "quarry.h"
#include "ui_quarry.h"

Quarry::Quarry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quarry)
{
    ui->setupUi(this);
    ui->stone->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/stone.png"));
    ui->stone_2->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/stone.png"));
    ui->stone_3->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/stone.png"));
    ui->stone_4->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/stone.png"));
    ui->stone_5->setPixmap(QPixmap("C:/Users/Grzdz/Documents/TheGame/Imgs/stone.png"));
}

Quarry::~Quarry()
{
    delete ui;
}

void Quarry::on_exit_clicked()
{
    this->close();
}

void Quarry::on_pushButton_clicked()
{
    NumberOfStone++;
}
