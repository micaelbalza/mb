#include "cutbox.h"
#include <iostream>

using namespace std;

/** @brief Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
 * e atribui aos mesmos a cor atual de desenho
 */
/**
 * @brief Construtor da classe CutBox
 */
CutBox::CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1)
{
    x0=_x0; x1=_x1;
    y0=_y0; y1=_y1;
    z0=_z0; z1=_z1;
}

/**
 * @brief Destrutor da classe CutBox
 */

CutBox::~CutBox() {

}

void CutBox::draw(Sculptor &t) {

    int i=x0; int j=y0; int k=z0;
    for (i;i<x1;i++) {
        for (j;j<y1;j++) {
            for (k;k<z1;k++) {

                /*i percorrerá entre os intervalos atribuidos a x0 e x1
                  j entre y0 e y1 e k entre z0 e z1 para apagar um paralelepípedo  */

                t.CutVoxel(i,j,k);

            }
        }
    }
}
