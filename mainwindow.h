#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "diagsculptor.h"
#include "sculptor.h"
#include "figurageometrica.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 

private:
    Ui::MainWindow *ui;
    Sculptor* sculptor;
    Diagsculptor *dialogForm;
    int r, g, b, a;
    int coord_x, coord_y, coord_z, coord_linha, coord_col;
    int atual_plano;
    int current_drawing_option;
    std::vector<FiguraGeometrica *> fgs;

};

#endif // MAINWINDOW_H
