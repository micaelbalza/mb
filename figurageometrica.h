#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"
//#include <iostream>
//#include <sstream>
//#include <cmath>
//#include <fstream>
#include<string>
//#include <cstdlib>
#include <vector>

//std::vector<int>
/**
  @brief Classe abstrata FiguraGeometrica
  */

/*FiguraGeometrica é uma classe abstrata, servindo para representar objetos primitivos genéricos.*/

class FiguraGeometrica
{
protected:
  int id;
    /* Não será preciso fazer um void virtual para as cores.*/
public:
    FiguraGeometrica();
    virtual void draw(Sculptor &t)=0;   //Será a função virtual pura pois ela se iguala a zero.
    virtual ~FiguraGeometrica(); //***************************&&&&&&&&&&&&&&&&&&&&
    //***************************&&&&&&&&&&&&&&&&&&&&

};

/* A função virtual draw(Sculptor &t) existe para ser chamada pelas outras subclasses */



class PutVoxel : public FiguraGeometrica
{
    int x, y, z;
    float r, g, b, a;
public:
    PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
    ~PutVoxel();
};


class CutVoxel : public FiguraGeometrica
{
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    void draw(Sculptor &t);
    ~CutVoxel();
};


class PutBox : public FiguraGeometrica
{
    int x0, x1, y0, y1, z0, z1;
    float r, g, b, a;
public:
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
    ~PutBox();
};


class CutBox : public FiguraGeometrica
{
protected:
    int x0, x1, y0, y1, z0, z1;
public:
    CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);
    void draw(Sculptor &t);
    ~CutBox();
};


class PutSphere : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;
public:
    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
    ~PutSphere();
};


class CutSphere : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
    void draw(Sculptor &t);
    ~CutSphere();
};


class PutEllipsoid : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, rx, ry, rz;
    float r, g, b, a;
public:
    PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
    ~PutEllipsoid();
};



class CutEllipsoid : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);
    void draw(Sculptor &t);
    ~CutEllipsoid();
};
//std::vector<string> split_string(string s);

//std::vector<string> split_string(string s);


Sculptor* load_sculpt_from_file(const char* filename);

// ---------------************************-------------
     //       INCLUIR PARTES DO FIGURA GEOMETRICA
// ---------------************************-------------


#endif // FIGURAGEOMETRICA_H
