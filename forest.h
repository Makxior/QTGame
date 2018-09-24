#ifndef FOREST_H
#define FOREST_H

#include <QDialog>
#include <QTimer>
#include <thegame.h>

namespace Ui {
class Forest;
}

class Forest : public QDialog
{
    Q_OBJECT

public:
    explicit Forest(QWidget *parent = nullptr);
    ~Forest();
    friend void TheGame::GettingWood();


private slots:
    void on_pushButton_clicked();

    void on_exit_clicked();

    void CutATree();
    void GrownATree();
    void Unlock();

private:
    int NumberOfWood=0;
    int NumberOfTrees =5;
    Ui::Forest *ui;
};

#endif // FOREST_H
