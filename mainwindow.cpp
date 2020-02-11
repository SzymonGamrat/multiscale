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


void MainWindow::on_SetScene_clicked() //set scene
{

        table = new Table(ui->sizeX->value(),ui->sizeY->value(),scene);

        //this->table->randomColor(this->scene);

        //table->exportToFile();
        table->grainsAmount = ui->spinBox_2->value();
        ui->graphicsView->setScene(this->scene);
        ui->frame->setEnabled(true);
        ui->Inclusion->setEnabled(true);
        ui->export_2->setEnabled(true);
        //ui->graphicsView->show();


}

void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}




void MainWindow::on_export_2_clicked() //export
{    
    this->table->exportToFile();
}

void MainWindow::on_import_2_clicked() //import
{

    table = new Table(scene);
    ui->graphicsView->setScene(this->scene);
}

void MainWindow::on_Inclusion_stateChanged(int arg1)
{
    if (ui->Inclusion->checkState() == 2){
        this->table->inclusion_active = 1;
    } else {
        this->table->inclusion_active = 0;
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(this->table->inclusionAdditionState == 1){
        this->table->addRandomInclusions();
    }

    //radio moore von neumann
    this->table->vonNeumann(ui);


    if(this->table->inclusionAdditionState == 2){
        this->table->addRandomInclusions();
    }
}

void MainWindow::on_InclusionSize_valueChanged(int arg1)
{
    this->table->inclusion_size = ui->InclusionSize->value();

}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{

}




void MainWindow::on_Circular_button_toggled(bool checked)
{
    if(checked) this->table->inclusionType = 1;
}

void MainWindow::on_Square_button_toggled(bool checked)
{
    if(checked) this->table->inclusionType = 2;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    this->table->inclusionAmount = ui->spinBox->value();
}

void MainWindow::on_pushButton_clicked()
{
    this->table->addRandomInclusions();
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    this->table->inclusionAmount = ui->spinBox_2->value();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->table->addRandomGrains();
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    if(checked) this->table->inclusionAdditionState = 1;
}

void MainWindow::on_radioButton_4_toggled(bool checked)
{
    if(checked) this->table->inclusionAdditionState = 2;
}
