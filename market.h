#ifndef MARKET_H
#define MARKET_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class Market;
}

class Market : public QDialog
{
    Q_OBJECT

public:
    explicit Market(QWidget *parent = nullptr);
    ~Market();
    void Start(int wood, int stone, int gold);
    int WoodExchanged{0},StoneExchanged{0},GoldExchanged{0};

private slots:
    void on_ExchangeWoodForGold_clicked();

    void on_exit_clicked();
    void UploadResources();

    void on_ExchangeStoneForWood_clicked();

    void on_ExchangeGoldForWood_clicked();

    void on_ExchangeStoneForGold_clicked();

    void on_ExchangeGoldForStone_clicked();

    void on_ExchangeWoodForStone_clicked();

private:
    Ui::Market *ui;
    int AmountOfWood,AmountOfStone,AmountOfGold;
};

#endif // MARKET_H
