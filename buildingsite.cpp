#include "buildingsite.h"
#include "ui_buildingsite.h"

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
