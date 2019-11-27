#include "diagsculptor.h"
#include "ui_diagsculptor.h"

Diagsculptor::Diagsculptor(int nx, int ny, int nz, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diagsculptor)
{
    ui->setupUi(this);
    current_nx = nx;
    current_ny = ny;
    current_nz = nz;
}

Diagsculptor::~Diagsculptor()
{
    delete ui;
}

void Diagsculptor::on_nxSpinBox_valueChanged(int arg1)
{
    current_nx = arg1;
    emit mudanca_n(current_nx, current_ny, current_nz);
}


void Diagsculptor::on_nySpinBox_valueChanged(int arg1)
{
    current_ny = arg1;
    emit mudanca_n(current_nx, current_ny, current_nz);
}

void Diagsculptor::on_nzSpinBox_valueChanged(int arg1)
{
    current_nz = arg1;
    emit mudanca_n(current_nx, current_ny, current_nz);
}

