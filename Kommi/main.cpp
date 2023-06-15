#include "kommi.h"
#include "vershina.h"
#include "rebro.h"

#include <QApplication>

QVector <TOP> tops;
QVector <EDGE> edges;
QVector <QVector<int>> map;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TSP w;
    w.show();
    return a.exec();
}
