#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>
#include<vector>
#include <fstream>
#include <QGraphicsSceneMouseEvent>
#include <random>
#include <iterator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new GraphicsScene();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //set scene
{

        table = new Table(ui->spinBox->value(),ui->spinBox_2->value(),scene);

        //this->table->randomColor(this->scene);

        //table->exportToFile();

        ui->graphicsView->setScene(this->scene);

        //ui->graphicsView->show();


}

void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}




void MainWindow::on_pushButton_2_clicked() //export
{
    this->table->exportToFile();
}

void MainWindow::on_pushButton_3_clicked() //import
{

    table = new Table(scene);
    ui->graphicsView->setScene(this->scene);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->checkState() == 2){
        this->table->inclusion_active = 1;
    } else {
        this->table->inclusion_active = 0;

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    this->table->vonNeumann();
}
