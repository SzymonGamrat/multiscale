
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
#include <map>
#include <math.h>

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

void Table::setInclusionColor(int id, QGraphicsItem *item){

    QGraphicsRectItem *rect2 = qgraphicsitem_cast<QGraphicsRectItem *>(item);

    int random_color = 9;
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

int Table::getPeriodicX(int j){
    if(j > this->size_x-1) return 0;
    if(j < 0) return this->size_x-1;
    return j;
}
int Table::getPeriodicY(int i){
    if(i > this->size_y-1) return 0;
    if(i < 0) return this->size_y-1;
    return i;
}

//for inclusion in graphicssene
int Table::getPeriodicInclusionX(int j){

    int pixel_size = this->size_x*this->grains[0]->settings->h;
    if(j >= pixel_size) return j-pixel_size;
    if(j <= 0) return pixel_size+j;
    return j;
};
int Table::getPeriodicInclusionY(int i){
    int pixel_size = this->size_y*this->grains[0]->settings->h;

    if(i >= pixel_size) return i-pixel_size;
    if(i <= 0) return pixel_size+i;
    return i;
};

bool Table::isInCircle(int rx, int ry, int new_rx, int new_ry,int inclusion_size){
    int param = pow((new_rx-rx), 2) + pow((new_ry-ry),2);
    double d = sqrt(param);
    if(d < (inclusion_size/2)*5) return true;
    else {
        return false;
    }

};

void Table::vonNeumann(Ui::MainWindow *ui){

 for (int i = 0; i < 100; i++){

   for (int i=0; i < this->size_y; i++){
           for (int j=0; j < this->size_x; j++){
               std::map<int, int> color_count;

               //x,y
               int current_id = j + i*this->size_x;

               //x-1, y
               int id = getPeriodicX(j-1) + i*this->size_x;

               if (grains[id]->color && grains[id]->color != 9){
                   color_count[grains[id]->color]++;

                 }

               //x+1, y
               id = getPeriodicX(j+1) + i*this->size_x;
               if (grains[id]->color && grains[id]->color != 9)
                   color_count[grains[id]->color]++;

               //x, y+1
               id = j + getPeriodicY(i+1)*this->size_x;
               if (grains[id]->color && grains[id]->color != 9)
                   color_count[grains[id]->color]++;

               //x, y-1
               id = j + getPeriodicY(i-1)*this->size_x;
               if (grains[id]->color && grains[id]->color != 9)
                   color_count[grains[id]->color]++;

               int max_value = 0;
               int max_key = 0;
               for(std::map<int,int>::iterator it=color_count.begin(); it !=color_count.end(); ++it){
                   if(it->second > max_value){
                       max_value = it->second;
                       max_key = it->first;

                   }
               }

               if(color_count.size()){
                 grains[current_id]->new_color = max_key;
               }

               if (grains[current_id]->color == 9){
                   grains[current_id]->new_color = 9;
               }

           }
       }

       for (int i = 0; i < size_x*size_y; i++){
           grains[i]->updateColor();
       }
   }
}


void Table::addInlusion(QPointF position){
    int block_size = this->grains[0]->settings->h;

    int size = this->inclusion_size;


    int ry = (int)position.ry();
        if (!ry) ry++;
        if (ry == 1500) ry--;
    int rx = (int)position.rx();
        if (!rx) rx++;
        if (rx == 1500) rx--;

    int new_ry = 0;
    int new_rx = 0;

    for (int i = size/2 * -1; i< size/2 + size%2; i++){
        int temp_ry = ry + i*5;
        new_ry = this->getPeriodicInclusionY(temp_ry);
        position.setY(new_ry);
        for (int j = size/2 * -1; j< size/2 + size%2; j++){
          new_rx = this->getPeriodicInclusionX(rx + j*5);
          position.setX(new_rx);

          if(this->inclusionType == 1){
               if(this->isInCircle(rx,ry,new_rx,new_ry,size)){
                   QGraphicsItem *item2 = this->scene->itemAt(position, QTransform());
                   this->setInclusionColor(this->getIdByAxles(new_rx, new_ry, block_size), item2);
               }
           }
          else if(this->inclusionType == 2){
                   QGraphicsItem *item2 = this->scene->itemAt(position, QTransform());
                   this->setInclusionColor(this->getIdByAxles(new_rx, new_ry, block_size), item2);
          }
        }
    }
}

void Table::addRandomInclusions(){
    for(int i = 0; i < this->inclusionAmount; i++){
       int randomId = rand() % (this->size_x*this->size_y);
       addInlusion(randomId);
    }
}

void Table::addInlusion(int grainId){
    int block_size = this->grains[0]->settings->h;

    int size = this->inclusion_size;
    QPointF position;

    position.setX(grains[0]->getAxleX(grainId,size_x,grains[0]->settings->h));
    position.setY(grains[0]->getAxleY(grainId,size_y,grains[0]->settings->h));

    int ry = (int)position.ry();
        if (!ry) ry++;
        if (ry == 1500) ry--;
    int rx = (int)position.rx();
        if (!rx) rx++;
        if (rx == 1500) rx--;

    int new_ry = 0;
    int new_rx = 0;

    for (int i = size/2 * -1; i< size/2 + size%2; i++){
        int temp_ry = ry + i*5;

        new_ry = this->getPeriodicInclusionY(temp_ry);
        if (!new_ry) new_ry++;
        if (new_ry == 1500) new_ry--;
        position.setY(new_ry);
        for (int j = size/2 * -1; j< size/2 + size%2; j++){
          new_rx = this->getPeriodicInclusionX(rx + j*5);
          if (!new_rx) new_rx++;
          if (new_rx == 1500) new_rx--;
          position.setX(new_rx);

          int dupa = this->inclusionType;

          if(this->inclusionType == 1){
               if(this->isInCircle(rx,ry,new_rx,new_ry,size)){
                   QGraphicsItem *item2 = this->scene->itemAt(position, QTransform());
                   this->setInclusionColor(this->getIdByAxles(new_rx, new_ry, block_size), item2);
               }
           }
          else if(this->inclusionType == 2){
                   QGraphicsItem *item2 = this->scene->itemAt(position, QTransform());
                   this->setInclusionColor(this->getIdByAxles(new_rx, new_ry, block_size), item2);
          }
        }
    }
}
void Table::addGrain(int grainId){

    QPointF position;
    position.setX(grains[0]->getAxleX(grainId,size_x,grains[0]->settings->h));
    position.setY(grains[0]->getAxleY(grainId,size_y,grains[0]->settings->h));
    QGraphicsItem *item = this->scene->itemAt(position, QTransform());
    setColorById(getIdByAxles(position.rx(), position.ry(), grains[0]->settings->h), item);

}

void Table::addRandomGrains(){
    for(int i = 0; i < this->grainsAmount; i++){
       int randomId = rand() % (this->size_x*this->size_y);
       addGrain(randomId);
    }

}


Table::Table(int size_x, int size_y, QGraphicsScene* scene)
{
    GraphicsScene* myscene = dynamic_cast<GraphicsScene *>(scene);
    myscene->setTable(this);
    this->scene = myscene;

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
    this->scene = myscene;
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
