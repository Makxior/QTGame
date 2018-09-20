#include "forest.h"
#include "thegame.h"
#include "ui_forest.h"

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
    NumberOfWood++;
}

void Forest::on_exit_clicked()
{
    this->close();
}
