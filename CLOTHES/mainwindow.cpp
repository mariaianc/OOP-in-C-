#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(Shop_controller *c, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller_clothes = c;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ADDpushButton_clicked()
{
    int id = ui->IDlineEdit->text().toInt();
    float price = ui->PRICElineEdit->text().toFloat();

    Clothes* clothesObject=new Clothes{price, id};

    controller_clothes->add(clothesObject);

    // Sunt randuri cate elemente sunt in vector
    ui->clothesTableWidget->setRowCount(controller_clothes->size());


    for (int i = 0; i < controller_clothes->size(); i++) {
        // In tabel adaugam elemente de tipul QTableWidgetItem
        // care in constructor pot avea doar QString, de exemplu aici convertim numar la QString cu QString::number()

        QTableWidgetItem *clothesId = new QTableWidgetItem(QString::number(controller_clothes.get(i)->get_id()));
        QTableWidgetItem *clothesPrice = new QTableWidgetItem(QString::number(controller_clothes.get(i)->get_price()));

        // setItem(rand, coloana, text)
        ui->clothesTableWidget->setItem(i, 0, clothesId);
        ui->clothesTableWidget->setItem(i, 1, clothesPrice);
    }

}


void MainWindow::on_DELETEpushButton_clicked()
{
        int id = ui->IDlineEdit->text().toInt();

        // O sa stearga mai multe daca au acelasi id
        for (int i = 0; i < clothes.size(); i++) {
            if ( clothes.get(i)->get_id()== id) {
                clothes.remove(clothes.get(i)->get_id());
            }
        }

        ui->clothesTableWidget->setRowCount(clothes.size());


        for (int i = 0; i < clothes.size(); i++) {
            // In tabel adaugam elemente de tipul QTableWidgetItem
            // care in constructor pot avea doar QString, de exemplu aici convertim numar la QString cu QString::number()

            QTableWidgetItem *clothesId = new QTableWidgetItem(QString::number(clothes.get(i)->get_id()));
            QTableWidgetItem *clothesPrice = new QTableWidgetItem(QString::number(clothes.get(i)->get_price()));

            // setItem(rand, coloana, text)
            ui->clothesTableWidget->setItem(i, 0, clothesId);
            ui->clothesTableWidget->setItem(i, 1, clothesPrice);
        }

}

/*
void MainWindow::keyPressEvent( QKeyEvent * e)
{
   QMessageBox msgBox;

    if(e->key()==Qt::Key_Enter)
    {
        msgBox.setText("OK");
        msgBox.exec();
    }

    MainWindow::keyPressEvent(e);
}
*/





void MainWindow::on_UNDOpushButton_clicked()
{

}


void MainWindow::on_REDOpushButton_clicked()
{

}

