#ifndef BUILDINGSITE_H
#define BUILDINGSITE_H
#include <QDialog>
#include <QTimer>

namespace Ui {
class BuildingSite;
}

class BuildingSite : public QDialog
{
    Q_OBJECT

public:
    explicit BuildingSite(QWidget *parent = nullptr);
    ~BuildingSite();

    int AmountOfWood,AmountOfStone,AmountOfGold;
    int WoodSpent{0},StoneSpent{0},GoldSpent{0};
    void Start(int W,int S,int G,bool SB,bool Q,bool WBB,bool SBB,bool GBB,bool MB);
    bool SawmillBuilt,QuarryBuilt,WoodBoostBuilt,StoneBoostBuilt,GoldBoostBuilt,Marketbuilt;

private slots:
    void on_exit_clicked();
    void UploadResources();

    void on_BuildWoodBoost_clicked();

    void on_Buildsawmill_clicked();



private:
    Ui::BuildingSite *ui;
};

#endif // BUILDINGSITE_H
