#ifndef THEGAME_H
#define THEGAME_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QCloseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsItem>
#include <QTime>
#include <QSound>


struct Resources
{
    int wood;
    int gold ;
    int stone;
};

namespace Ui {
class TheGame;
}

class TheGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheGame(QWidget *parent = nullptr);
    ~TheGame();
    void keyPressEvent(QKeyEvent * event);
    void GettingWood();
    void GettingStone();
    void UploadResources();
    void Building();
    Resources resources{50,50,50};
    QTimer *sawmillTimer = new QTimer(this);
    QTimer *quarryTimer = new QTimer(this);

private slots:

    void on_actionNew_triggered();

    void on_actionLoad_triggered();

    void on_actionSave_triggered();
    void Move(QLabel* player, int dir, int dir2);
    void Sawmill();
    void Quarry();
    void LeaveASite();


private:
    bool SawmillBuilt{false},QuarryBuilt{false},WoodBoostBuilt{false},StoneBoostBuilt{false},GoldBoostBuilt{false},Marketbuilt{false};
    int HowMuchWood{1},HowMuchStone{1},HowMuchGold{1},ChanceForGold{1};
    int player;
    Ui::TheGame *ui;
    QString currentFile{""};
};

#endif // THEGAME_H
