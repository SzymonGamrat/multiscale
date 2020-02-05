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


void MainWindow::on_pushButton_clicked()
{

        table = new Table(ui->spinBox->value(),ui->spinBox_2->value(),scene);

        this->table->randomColor(this->scene);

        //table->exportToFile();

        ui->graphicsView->setScene(this->scene);

        //ui->graphicsView->show();


}

void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}



void MainWindow::on_pushButton_2_clicked()
{
    this->table->exportToFile();
}
