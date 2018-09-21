#include "quarry.h"
#include "ui_quarry.h"
#include <QSound>

Quarry::Quarry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quarry)
{
    ui->setupUi(this);
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
    QSound::play(":/Sounds/Sounds/Quarry.wav");
    NumberOfStone++;
}
