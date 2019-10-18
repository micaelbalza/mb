#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"

/**
  @brief Classe concreta PutVoxel
  */

/* O voxel deve especificar o desenho de acordo com sua posição no espaço e
suas cores, podendo ou não terem transparência. As outras subclasses também serão
feitas desta forma, de acordo como cada figura geométrica é representada.*/

class PutVoxel : public FiguraGeometrica
{
    int x, y, z;
    float r, g, b, a;
public:
    PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
    //~PutVoxel;
};

#endif // PUTVOXEL_H
