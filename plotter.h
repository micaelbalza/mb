#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QObject>
#include <QAction>
#include <QMouseEvent>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include "sculptor.h"

class Plotter : public QWidget
{

  Q_OBJECT

private:
    QAction *actionMessage;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
   // void contextMenuEvent (QContextMenuEvent *event);
    //void setBackgroundColor(int r, int g, int b);
    void DrawBackground();
    void DrawGrid();
    void updateGridInfo();
    void setAtual_x (int value);
    void setAtual_y (int value);
    void setAtual_z (int value);
    void linhaAtual (int value);
    void colunaAtual (int value);
    void set_AtualPlano (int value);
    void SculptorAtualizar (Sculptor* sculptor, int Atual_x, int Atual_y, int Atual_z, int AtualPlano);
    void AtualizarGrid();

protected:
    Sculptor* sculpt;
    QPen pen;
    QBrush brush;
    int lado;
    int num_vertical;
    int num_horizontal;
    int Atual_x;
    int Atual_y;
    int Atual_z;
    int AtualPlano;
    int selected_row;
    int selected_col;
    bool vertical_grid;
    int square_size;
    int margin_size_hor;
    int margin_size_ver;
    int click_min_valid_hor;
    int click_max_valid_hor;
    int click_min_valid_ver;
    int click_max_valid_ver;
    int click_x_fixed;
    int click_y_fixed;
    int selected_square_row;
    int selected_square_col;



//permite a interação entre o mouse e a matriz, permitindo desenhar a figura desejada

signals:
    /*void mouseX(int);
    void mouseY(int);                      ///____________________________________obs sinais a menos--------------------------
    void linha_selecionada(int);
    void coluna_selecionada(int);
*/
        void positions(int x, int y, int z, int selected_row, int selected_col, bool sculptUpdated);
//public slots:
    //void mudaFigura();

};

#endif // PLOTTER_H
