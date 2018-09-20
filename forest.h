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

private:
    Ui::Forest *ui;
};

#endif // FOREST_H
