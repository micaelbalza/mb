#include "putbox.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Ativa todos os voxels na posição x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui os mesmos
 * à cor atual do desenho.
 */

/* Será desenhado um paralelepípedo com intervalos delimitados nas três dimensões
   e com suas respectivas cores */
/**
 * @brief Construtor da classe PutBox
 */
PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a)
{
    x0=_x0; x1=_x1;
    y0=_y0; y1=_y1;
    z0=_z0; z1=_z1;
    r=_r; g=_g; b=_b; a=_a;
}
/**
 * @brief Destrutor da classe PutBox
 */
PutBox::~PutBox() {

}

void PutBox::draw(Sculptor &t) {
    t.SetColor(r,g,b,a);
    int i=x0; int j=y0; int k=z0;
    for (i;i<=x1;i++) {
        for (j;j<=y1;j++) {
            for (k;k<=z1;k++) {
                t.PutVoxel(i,j,k);
            }
        }
    }
}
