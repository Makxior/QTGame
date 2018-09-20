#ifndef QUARRY_H
#define QUARRY_H

#include <QDialog>

namespace Ui {
class Quarry;
}

class Quarry : public QDialog
{
    Q_OBJECT

public:
    explicit Quarry(QWidget *parent = nullptr);
    ~Quarry();
    friend int GettingStone();

private slots:
    void on_exit_clicked();

    void on_pushButton_clicked();

private:
    int NumberOfStone=0;
    Ui::Quarry *ui;
};

#endif // QUARRY_H
