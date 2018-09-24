#ifndef BUILDINGSITE_H
#define BUILDINGSITE_H

#include <QDialog>
#include <thegame.h>

namespace Ui {
class BuildingSite;
}

class BuildingSite : public QDialog
{
    Q_OBJECT

public:
    explicit BuildingSite(QWidget *parent = nullptr);
    ~BuildingSite();
    friend void TheGame::Building();

private:
    Ui::BuildingSite *ui;
};

#endif // BUILDINGSITE_H
