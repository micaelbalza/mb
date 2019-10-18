#include "cutsphere.h"
#include <iostream>
#include <cmath>

using namespace std;

/** @brief Desativa todos os voxels que satisfazem à equação da esfera
*/

/**
 * @brief Construtor da classe CutSphere
 */

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}
/**
 * @brief Destrutor da classe CutSphere
 */
CutSphere::~CutSphere(){

}

void CutSphere::draw(Sculptor &t) {

   //int i=0; int j=0; int k=0;
    for(int i = xcenter-radius; i<=xcenter+radius; i++){
            for(int j = ycenter-radius; j<=ycenter+radius; j++){
                for(int k = zcenter-radius; k<=zcenter+radius; k++){
                if((i-xcenter)^2+(j-ycenter)^2+(k-zcenter)^2 <= (radius)^2) {
                    t.CutVoxel(i,j,k);
                }
            }
        }
    }

}
