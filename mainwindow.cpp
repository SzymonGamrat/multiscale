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



class GraphicsScene : public QGraphicsScene

{    

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        QGraphicsScene::mousePressEvent(event);
        if(event->button() == Qt::LeftButton) {
            QPointF position = event->scenePos();
            QGraphicsItem *item = itemAt(position, QTransform());// it is your clicked item, you can do everything what you want. for example send it somewhere
            QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(item);
            rect->setBrush(QBrush(Qt::yellow));
            for (int i = -10/2; i<10/2; i++){
                position.setX(position.rx()+i-1);
                position.setY(position.ry()+i);
                for (int j = -10/2; j<10/2; j++){
                  position.setX(position.rx()+j);
                  position.setY(position.ry()+j);
                  QGraphicsItem *item2 = itemAt(position, QTransform());
                  QGraphicsRectItem *rect2 = qgraphicsitem_cast<QGraphicsRectItem *>(item2);
                  rect2->setBrush(QBrush(Qt::green));
                }
            }
        }
    }
};

//==========================================================================================================
class Color
{
public:

    int id;
    Qt::GlobalColor brush;

    Color(int _id, Qt::GlobalColor _brush);
    ~Color();

private:

};

Color::Color(int _id, Qt::GlobalColor _brush)
{
        this->id = _id;
        this->brush = _brush;
}

Color::~Color()
{
}
//==========================================================================================================

class GrainSettings
{
public:
    int ax, ay, h, w;
    GrainSettings(int _ax, int _ay, int _h, int _w);
    ~GrainSettings();

private:

};

GrainSettings::GrainSettings(int _ax, int _ay, int _h, int _w)
{
    this->ax = _ax;
    this->ay = _ay;
    this->h = _h;
    this->w = _w;
}

GrainSettings::~GrainSettings()
{
}
//==========================================================================================================


class Grain
{
public:

    int id;
    std::vector<Color*> colors;

    int color;
    GrainSettings* settings;
    QGraphicsScene* scene;
    QGraphicsRectItem* rect;


    int getAxleX(int id, int _table_x, int block_size);
    int getAxleY(int id, int _table_y, int block_size);
    void draw(QGraphicsScene* scene);
    void setColors();
    Color randColor();
    Qt::GlobalColor getColor(int colorId);

    Grain(int _id, int _color, int _table_x, int _table_y, QGraphicsScene* scene);
    ~Grain();

private:

};

int Grain::getAxleX(int id, int _table_x, int block_size) {
    int return_ax = 0;
    return_ax = (id % _table_x) * block_size;
    return return_ax;

}

int Grain::getAxleY(int id, int _table_y, int block_size) {
    int return_ay = 0;
    return_ay = ((id / _table_y) - 1) * block_size;
    return return_ay;

}

void Grain::draw(QGraphicsScene* scene) {

    this->rect = new QGraphicsRectItem();
    rect->setRect(this->settings->ax, this->settings->ay, this->settings->h, this->settings->w);

    rect->setBrush(Qt::black);
    scene->addItem(rect);
}

void Grain::setColors(){

    this->colors.push_back(new Color(0, Qt::black));
    this->colors.push_back(new Color(5, Qt::yellow));
    this->colors.push_back(new Color(15, Qt::red));
    this->colors.push_back(new Color(20, Qt::cyan));
    this->colors.push_back(new Color(25, Qt::magenta));
    this->colors.push_back(new Color(30, Qt::gray));
    this->colors.push_back(new Color(35, Qt::white));
    this->colors.push_back(new Color(40, Qt::darkMagenta));
    this->colors.push_back(new Color(45, Qt::darkGreen));


}
Color Grain::randColor(){

        int randomColor = rand() % this->colors.size();


}
Qt::GlobalColor Grain::getColor(int colorId)
{
    for (int i = 0; i < this->colors.size(); i++)
    {
        if (this->colors[i]->id == colorId) {
            return this->colors[i]->brush;
        }
        else if (colorId > this->colors.size()) {
            return Qt::white;
        }


    }


}

Grain::Grain(int _id, int _color, int _table_x, int _table_y, QGraphicsScene* scene)
{

    this->id = _id;
    this->color = _color;
    int block_size = 5;
    this->settings = new GrainSettings(this->getAxleX(this->id, _table_x, block_size),this->getAxleY(this->id, _table_y, block_size), block_size, block_size);
    this->draw(scene);
}

Grain::~Grain()
{
}
//==========================================================================================================

class Table
{
public:

    int size_x, size_y;
    std::vector<Grain*> grains;

    void exportToFile();
    void randomColor(QGraphicsScene* scene);

    Table(int size_x, int size_y, QGraphicsScene* scene);
    ~Table();

private:

};


void Table::exportToFile(){

    std::ofstream ofs("export.txt", std::ofstream::out);

    for (int i = 0; i < this->grains.size(); i++)
    {
        ofs << this->grains[i]->id;
        ofs << this->grains[i]->color << std::endl;
    }

    ofs.close();
}

void Table::randomColor(QGraphicsScene* scene) {
    for (int i = 0; i < this->size_x; i++) {
        if (i % 5 == 0) {
            this->grains[i]->rect->setBrush( this->grains[i]->getColor(i) );
        }

    }

    scene->update();

}

Table::Table(int size_x, int size_y, QGraphicsScene* scene)
{

    this->size_x = size_x;
    this->size_y = size_y;

    for (int i = 0; i < (this->size_x * this->size_y); i++)
    {
        grains.push_back(new Grain(i, 0, this->size_x, this->size_y, scene));
    }
}

Table::~Table()
{
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
        GraphicsScene* scene = new GraphicsScene();
        Table* table = new Table(ui->spinBox->value(),ui->spinBox_2->value(),scene);        

        table->randomColor(scene);

        //table->exportToFile();

        ui->graphicsView->setScene(scene);

        //ui->graphicsView->show();


}

void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}

