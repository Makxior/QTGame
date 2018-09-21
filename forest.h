#ifndef FOREST_H
#define FOREST_H

#include <QDialog>
namespace Ui {
class Forest;
}

class Forest : public QDialog
{
    Q_OBJECT

public:
    explicit Forest(QWidget *parent = nullptr);
    ~Forest();
    friend int GettingWood();

private slots:
    void on_pushButton_clicked();

    void on_exit_clicked();

private:
    int NumberOfWood=0;
    Ui::Forest *ui;
};

#endif // FOREST_H
