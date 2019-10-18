#include "cutellipsoid.h"
#include <iostream>
#include <cmath>

using namespace std;

/** @brief Desativa todos os voxels que satisfazem à equação do elipsóide */



/**
 * @brief Construtor da classe CutEllipsoid
 */
CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx=_rx; ry=_ry; rz=_rz;
}

/**
 * @brief Destrutor da classe CutEllipsoid
 */
CutEllipsoid::~CutEllipsoid() {

}

void CutEllipsoid::draw(Sculptor &t) {
    int i=0; int j=0; int k=0;
    for (i; i<rx; i++) {
       for (j; j<ry; j++) {
           for (k; k<rz; k++) {
              if(((pow((i - xcenter),2)/(float)pow(rx,2) + (pow((j - ycenter),2))/(float)pow(ry,2) + (pow((k - zcenter),2))/(float)pow(rz,2)) <= 1))
              {
                    t.CutVoxel(i,j,k);
               }
            }
        }
    }

}
