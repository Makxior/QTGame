#include "thegame.h"
#include "ui_thegame.h"

TheGame::TheGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheGame)
{
    ui->setupUi(this);
}

TheGame::~TheGame()
{
    delete ui;
}
