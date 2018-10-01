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
    int WoodBalance{0},StoneBalance{0},GoldBalance{0};
    void Start(int W,int S,int G,bool SB,bool Q,bool WBB,bool SBB,bool GBB,bool MB);
    bool SawmillBuilt{false},QuarryBuilt{false},WoodBoostBuilt{false},StoneBoostBuilt{false},GoldBoostBuilt{false},Marketbuilt{false};

private slots:
    void on_exit_clicked();
    void UploadResources();

    void on_BuildWoodBoost_clicked();

    void on_Buildsawmill_clicked();

    void on_BuildQuarry_clicked();

    void on_BuildMarket_clicked();

    void on_BuildStoneBoost_clicked();

    void on_BuildGoldBoost_clicked();


    void on_EnterMarket_clicked();

private:
    Ui::BuildingSite *ui;
};

#endif // BUILDINGSITE_H
