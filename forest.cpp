#include "forest.h"
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
