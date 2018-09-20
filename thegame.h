#ifndef THEGAME_H
#define THEGAME_H

#include <QMainWindow>

namespace Ui {
class TheGame;
}

class TheGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheGame(QWidget *parent = nullptr);
    ~TheGame();

private:
    Ui::TheGame *ui;
};

#endif // THEGAME_H
