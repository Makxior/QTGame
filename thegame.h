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

private slots:
    void on_actionNew_triggered();

    void on_actionLoad_triggered();

    void on_actionSave_triggered();
    void Move(QLabel* player, int dir, int dir2);

private:
    int wood{0};
    int stone{0};
    int player;
    Ui::TheGame *ui;
    QString currentFile{""};
};

#endif // THEGAME_H
