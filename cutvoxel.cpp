#include "cutvoxel.h"
#include <iostream>

using namespace std;
/**
 * @brief Construtor da classe CutVoxel
 */
CutVoxel::CutVoxel(int _x, int _y, int _z)
{
    x=_x; y=_y; z=_z;
}
/**
 * @brief Destrutor da classe CutVoxel
 */
CutVoxel::~CutVoxel(){

}

void CutVoxel::draw (Sculptor &t) {
    t.CutVoxel(x,y,z);
}
