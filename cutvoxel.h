#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

/**
  @brief Classe concreta cutVoxel
  */

class CutVoxel : public FiguraGeometrica
{
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    void draw(Sculptor &t);
    ~CutVoxel();
};

#endif // CUTVOXEL_H
