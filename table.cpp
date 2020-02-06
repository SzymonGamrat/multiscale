
#include "table.h"
#include "grain.h"
#include <iostream>
#include <fstream>
#include "graphicsscene.h"
#include <string>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsView>
#include <sstream>

int Table::getIdByAxles(int ax, int ay, int block_size){

    int id = 0;
    id = ax/block_size + ay/block_size* this->size_x;
    return id;

}


void Table::exportToFile(){

    std::ofstream ofs("export.txt", std::ofstream::out);

    ofs << this->size_x << " ";
    ofs << this->size_y << std::endl;

    for (int i = 0; i < this->grains.size(); i++)
    {
        ofs << this->grains[i]->id << " ";
        ofs << this->grains[i]->color << std::endl;
    }

    ofs.close();
}

void Table::setColorById(int id, QGraphicsItem *item){

    QGraphicsRectItem *rect2 = qgraphicsitem_cast<QGraphicsRectItem *>(item);

    int random_color = this->grains[id]->randColor();
    rect2->setBrush(this->grains[id]->getColor(random_color));

    this->grains[id]->color = random_color;
}

void Table::randomColor(QGraphicsScene* scene) {
    for (int i = 0; i < this->size_x; i++) {
        if (i % 5 == 0) {
            this->grains[i]->rect->setBrush( this->grains[i]->getColor(i) );
        }

    }

    scene->update();

}

void Table::vonNeumann(){

   for (int i=1; i < this->size_x-1; i++){
           for (int j=1; j < this->size_y-1; j++){


               int id = 0;
               int count = 0;

               //x,y
               int current_id = j + i/this->size_x;

               //x, y-1
               id = j-1 + i/this->size_x;
               if (grains[id]->color) count = grains[id]->color;

               /*
               //x+1, y
               id = j + (i+1)/this->size_x;
               if (grains[id]->color) count = grains[id]->color;

               //x, y+1
               id = j+1 + i/this->size_x;
               if (grains[id]->color) count = grains[id]->color;

               //x-1, y
               id = j + (i-1)/this->size_x;
               if (grains[id]->color) count = grains[id]->color;
               */

               if (count) grains[current_id]->setColor(count);



           }
       }
}

Table::Table(int size_x, int size_y, QGraphicsScene* scene)
{
    GraphicsScene* myscene = dynamic_cast<GraphicsScene *>(scene);
    myscene->setTable(this);

    this->size_x = size_x;
    this->size_y = size_y;

    for (int i = 0; i < (this->size_x * this->size_y); i++)
    {
        grains.push_back(new Grain(i, 0, this->size_x, this->size_y, scene));
    }
}

Table::Table(QGraphicsScene* scene)
{
    GraphicsScene* myscene = dynamic_cast<GraphicsScene *>(scene);
    myscene->setTable(this);

        std::ifstream readFile;
        std::string line;
        readFile.open("export.txt");
        if(readFile.is_open()){

            int licznik = 0;

            while (std::getline(readFile,line)) {
                std::stringstream linestream(line);
                int val1;
                int val2;
                linestream >> val1 >> val2;

                if (licznik==0){
                    this->size_x = val1;
                    this->size_y = val2;
                }
                else {
                    grains.push_back(new Grain(val1, val2, this->size_x, this->size_y, scene));
                }

              licznik++;
            }
        }
     readFile.close();
}

Table::~Table()
{
}
