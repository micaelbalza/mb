#include "plotter.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <QMouseEvent>
#include <algorithm>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>

using namespace std;

Plotter::Plotter (QWidget *parent) : QWidget(parent)
{   // void setAtual_y (int value);

   sculpt = nullptr;
   Atual_x=0;
   Atual_y=0;
   Atual_z=0;
   selected_row=-1;
   selected_col=-1;
   AtualPlano=0;

    setMouseTracking(true);   //vai habilitar o rastreio do mouse

    actionMessage = new QAction(this);

}       // void SculptorAtualizar (Sculptor* sculptor, int Atual_x, int Atual_y, int Atual_z, int AtualPlano);


void Plotter::SculptorAtualizar (Sculptor* sculptor, int Atual_x, int Atual_y, int Atual_z, int AtualPlano)
{
    this -> sculpt = sculptor;
    this -> Atual_x = Atual_x;
    this -> Atual_y = Atual_y;
    this -> Atual_z = Atual_z;
    this -> AtualPlano = AtualPlano;
}

void Plotter::AtualizarGrid() {
    int n_hor;
    int n_ver;
    int lado_hor=0;
    int lado_ver=0;

    if (AtualPlano == 0) {
        n_hor = this->sculpt->getNx();
        n_ver = this -> sculpt ->getNy();
    }

    else if (AtualPlano == 1) {
        n_hor = this->sculpt->getNx();
        n_ver = this->sculpt->getNy();
    }

    else if (AtualPlano == 2) {
        n_hor = this->sculpt->getNz();
        n_ver= this->sculpt->getNx();
    }

    else {
        n_hor=this->sculpt->getNx();
        n_ver=this->sculpt->getNy();
    }

    n_hor=num_horizontal;
    n_ver=num_vertical;

    lado_hor=width()/num_horizontal;
    lado_ver=height()/num_vertical;

    if (lado_ver > lado_hor) {
        vertical_grid = false;
        lado = lado_hor;
    }

    else {
        vertical_grid = true;
        lado = lado_ver;
    }
    int actual_width = square_size * n_hor;
    int actual_height = square_size * n_ver;

    lado_hor = (width() - actual_width)/2;
    lado_ver = (height() - actual_height)/2;

    click_min_valid_hor = lado_hor;
    click_max_valid_hor = lado_hor + actual_width;
    click_min_valid_ver = lado_ver;
    click_max_valid_ver = lado_ver + actual_height;


}


void Plotter::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QPen pen;
  QBrush brush;

  painter.setRenderHint(QPainter::Antialiasing);

  pen.setColor(QColor(0,0,0));
  //brush.setColor(QColor(backR,backG,backB));
  pen.setStyle(Qt::SolidLine);
  pen.setWidth(2);

  painter.setPen(pen);
  painter.setBrush(brush);

  brush.setColor(Qt::white);
  brush.setStyle(Qt::SolidPattern);
  //painter.setPen(pen);

  painter.drawRect(0,0,width()-2,height()-2);
  //QRectF rectangle (0, 0, 40, 40);

  //painter.drawRect(rectangle);

  /*for (int i=0; i<width(); i++) {
      for (int j=0; j<height(); j++) {
          QRectF rectangle (i*40,j*40,40,40);
          painter.drawRect (rectangle);
      }
  } */
}

void Plotter::setAtual_x (int value) {
    Atual_x = value;
}

void Plotter::setAtual_y (int value) {
    Atual_y = value;
}

void Plotter::setAtual_z (int value) {
    Atual_z = value;
}

void Plotter::set_AtualPlano (int value) {
    AtualPlano = value;
}

void Plotter::DrawGrid() {
    int margin_hor = 0;
    int margin_ver = 0;
    margin_hor = std::max(0, margin_size_hor);
    margin_ver = std::max(0, margin_size_ver);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    this->pen.setStyle(Qt::SolidLine);
    this->pen.setWidth(1);
    this->brush.setColor(QColor(255, 255, 255, 0));
    painter.setBrush(brush);
    painter.setPen(pen);
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 0;

    int x0, y0;
    bool voxelEnabled = false;
    for (int row=0; row < num_vertical ; row++)
    {
        for (int col=0; col < num_horizontal; col++)
        {
            x0 = (col*square_size) + margin_hor;
            y0 = (row*square_size) + margin_ver;

            if(AtualPlano == 0)
            {
                voxelEnabled = this->sculpt->getV()[col][row][Atual_z].is0n;
                r = this->sculpt->getV()[col][row][Atual_z].r * 255;
                g = this->sculpt->getV()[col][row][Atual_z].g * 255;
                b = this->sculpt->getV()[col][row][Atual_z].b * 255;
                a = this->sculpt->getV()[col][row][Atual_z].a * 255;
            }
            else if(AtualPlano == 1)
            {

                voxelEnabled = this->sculpt->getV()[Atual_x][col][row].is0n;
                r = this->sculpt->getV()[Atual_x][col][row].r * 255;
                g = this->sculpt->getV()[Atual_x][col][row].g * 255;
                b = this->sculpt->getV()[Atual_x][col][row].b * 255;
                a = this->sculpt->getV()[Atual_x][col][row].a * 255;
            }
            else if(AtualPlano == 2)
            {
                voxelEnabled = this->sculpt->getV()[row][Atual_y][col].is0n;
                r = this->sculpt->getV()[row][Atual_y][col].r * 255;
                g = this->sculpt->getV()[row][Atual_y][col].g * 255;
                b = this->sculpt->getV()[row][Atual_y][col].b * 255;
                a = this->sculpt->getV()[row][Atual_y][col].a * 255;
            }
            else
            {
                voxelEnabled = false;
            }


            if(voxelEnabled)
            {
                this->pen.setWidth(2);
                this->pen.setColor(QColor(0,0,0,255));
                this->brush.setColor(QColor(r, g, b, a));
            }
            else
            {
                this->pen.setWidth(1);
                this->pen.setColor(QColor(180,180,180,255));
                this->brush.setColor(QColor(255, 255, 255, 0));
            }

            // selected square
            if (row == selected_square_row && col == selected_square_col)
            {
                this->pen.setWidth(2);
                this->pen.setColor(QColor(Qt::blue));
            }

            painter.setPen(pen);
            painter.setBrush(brush);
            painter.drawRect( QRect(x0, y0, square_size, square_size ) );
        }
    }

}



void Plotter::mousePressEvent (QMouseEvent *event) {
    if(this->sculpt != nullptr)
    {
        if(event->button() == Qt::LeftButton)
        {
            if(event->pos().x() > click_min_valid_hor && event->pos().x() < click_max_valid_hor)
            {
                if(event->pos().y() > click_min_valid_ver && event->pos().y() < click_max_valid_ver)
                {
                    click_x_fixed = event->pos().x() - click_min_valid_hor;
                    click_y_fixed = event->pos().y() - click_min_valid_ver;
                    selected_square_col = click_x_fixed/lado;
                    selected_square_row = click_y_fixed/lado;

                    if(AtualPlano == 0)
                    {
                        Atual_x = selected_square_col;
                        Atual_y = selected_square_row;
                    }
                    else if(AtualPlano == 1)
                    {
                        Atual_y = selected_square_col;
                        Atual_z = selected_square_row;
                    }

                    else if(AtualPlano == 2)
                    {
                        Atual_z = selected_square_col;
                        Atual_x = selected_square_row;
                    }
                }
            }
}

        else
        {
            selected_square_col = -1;
            selected_square_row = -1;
        }

        /*emit positions(Atual_x,
                       Atual_y,
                       Atual_z,
                       selected_square_row, selected_square_col, true);
*/

      // emit void mouseX(int);
        //void mouseY(int);                      ///____________________________________obs sinais a menos--------------------------
        //void linha_selecionada(int);
        //void coluna_selecionada(int);


    }
}

void Plotter::mouseMoveEvent (QMouseEvent *event) {
    if(event->pos().x() > click_min_valid_hor && event->pos().x() < click_max_valid_hor)
    {
        if(event->pos().y() > click_min_valid_ver && event->pos().y() < click_max_valid_ver)
        {
            click_x_fixed = event->pos().x() - click_min_valid_hor;
            click_y_fixed = event->pos().y() - click_min_valid_ver;
            selected_square_col = click_x_fixed/square_size;
            selected_square_row = click_y_fixed/square_size;

            if(AtualPlano == 0)
            {
                Atual_x = selected_square_col;
                Atual_y = selected_square_row;
            }
            else if(AtualPlano == 1)
            {
                Atual_y = selected_square_col;
                Atual_z = selected_square_row;
            }

            else if(AtualPlano == 2)
            {
                Atual_z = selected_square_col;
                Atual_x = selected_square_row;
            }
        }
    }

    else    {
        selected_square_col = -1;
        selected_square_row = -1;
    }

    emit positions(Atual_x, Atual_y, Atual_z, selected_square_row, selected_square_col, false);

}

