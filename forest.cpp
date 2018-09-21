#include "forest.h"
#include "thegame.h"
#include "ui_forest.h"
#include <QSound>

Forest::Forest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forest)
{
    ui->setupUi(this);
}

Forest::~Forest()
{
    delete ui;
}

void Forest::on_pushButton_clicked()
{
    QSound::play(":/Sounds/Sounds/Forest.wav");
    NumberOfWood++;
}

void Forest::on_exit_clicked()
{
    this->close();
}
