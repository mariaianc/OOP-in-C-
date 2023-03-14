#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Shop_repo.h"
#include "Shop_controller.h"
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Shop_controller* c,QWidget *parent = nullptr);
    ~MainWindow();

    //void keyPressEvent(QKeyEvent *e) override;

private slots:

    void on_ADDpushButton_clicked();

    void on_DELETEpushButton_clicked();

    void on_UNDOpushButton_clicked();

    void on_REDOpushButton_clicked();

private:
    Shop_controller *controller_clothes;
    //std::vector<Clothes> clothesVector;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
