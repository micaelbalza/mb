#include "putellipsoid.h"
#include <iostream>
#include <cmath>

using namespace std;

/** @brief Ativa todos os voxels que satisfazem à equação do elipsóide e atribui
 * aos mesmos a cor atual de desenho  */
/**
 * @brief Construtor da classe PutEllipsoid
 */
PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx=_rx; ry=_ry; rz=_rz;
    r = _r; g = _g; b = _b; a = _a;
}
/**
 * @brief Destrutor da classe PutEllipsoid
 */
PutEllipsoid::~PutEllipsoid() {

}

void PutEllipsoid::draw(Sculptor &t) {
    t.SetColor(r,g,b,a);
    int i=0; int j=0; int k=0;
    for (i; i<rx; i++) {
       for (j; j<ry; j++) {
           for (k; k<rz; k++) {
              if(((pow((i - xcenter),2)/(float)pow(rx,2) + (pow((j - ycenter),2))/(float)pow(ry,2) + (pow((k - zcenter),2))/(float)pow(rz,2)) <= 1))
              {
                    t.PutVoxel(i,j,k);
               }
            }
        }
    }

}
