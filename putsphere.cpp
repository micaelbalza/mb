#include "putsphere.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Ativa todos os voxels que satisfazem à equação da esfera e
 * atribui aos mesmos a cor atual de desenho (r,g,b,a)
 */
/**
 * @brief Construtor da classe PutSphere
 */
PutSphere::PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;

    r=_r; g=_g; b=_b; a=_a;

}
/**
 * @brief Destrutor da classe PutSphere
 */
PutSphere::~PutSphere() {

}

void PutSphere::draw(Sculptor &t) {
    t.SetColor(r,g,b,a);
    for(int i = xcenter-radius; i<=xcenter+radius; i++){
            for(int j = ycenter-radius; j<=ycenter+radius; j++){
                for(int k = zcenter-radius; k<=zcenter+radius; k++){
                if((i-xcenter)^2+(j-ycenter)^2+(k-zcenter)^2 <= (radius)^2) {
                    t.PutVoxel(i,j,k);
                }
            }
        }
    }

}
