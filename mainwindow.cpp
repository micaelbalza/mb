#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotter.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  /*  connect(ui->circuloX,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::mudaCirculoX);

    connect(ui->circuloY,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::mudaCirculoY);

    connect(ui->circuloZ,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::mudaCirculoZ);

    connect(ui->elipseRx,
            &QAbstractSlider::valueChanged,
            ui -> widget,
            &Plotter::mudaElipseRx);

    connect(ui->elipseRy,
            &QAbstractSlider::valueChanged,
            ui -> widget,
            &Plotter::mudaElipseRy);

    connect(ui->elipseRz,
            &QAbstractSlider::valueChanged,
            ui -> widget,
            &Plotter::mudaElipseRz);

    connect (ui->sphereRaio,
             &QAbstractSlider::valueChanged,
             ui -> widget,
             &Plotter::mudaSphere); */

}

MainWindow::~MainWindow()
{
    delete ui;
}

