#include "putvoxel.h"
#include <iostream>

using namespace std;
/**
 * @brief Construtor da classe PutVoxel
 */
PutVoxel::PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a)
{
    x=_x; y=_y; z=_z;
    r=_r; g=_g; b=_b; a=_a;

}
/**
 * @brief Destrutor da classe PutVoxel
 */
/*PutVoxel::~PutVoxel()
{

}*/

void PutVoxel::draw(Sculptor &t) {
    t.SetColor(r,g,b,a);
    t.PutVoxel(x,y,z);
}
