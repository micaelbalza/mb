#ifndef DIAGSCULPTOR_H
#define DIAGSCULPTOR_H

#include <QDialog>

namespace Ui {
class Diagsculptor;
}

class Diagsculptor : public QDialog
{
    Q_OBJECT

public:
    explicit Diagsculptor(int nx, int ny, int nz, QWidget *parent = nullptr);
    ~Diagsculptor();

private slots:
    void on_nxSpinBox_valueChanged(int arg1);
    void on_nySpinBox_valueChanged(int arg1);
    void on_nzSpinBox_valueChanged(int arg1);

signals:
    void mudanca_n(int _nx, int _ny, int _nz);

private:
    Ui::Diagsculptor *ui;
    int current_nx;
    int current_ny;
    int current_nz;
};


#endif // DIAGSCULPTOR_H
