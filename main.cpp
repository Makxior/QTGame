#include "thegame.h"
#include "quarry.h"
#include "forest.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TheGame w;
    w.show();

    return a.exec();
}
