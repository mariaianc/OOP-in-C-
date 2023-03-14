#include "mainwindow.h"
#include "Shop_controller.h"
#include "Shop_repo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shop_repo repo;
    Shop_controller c(repo);
    MainWindow w(&c);
    w.show();
    return a.exec();
}
