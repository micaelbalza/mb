#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief Estrutura do voxel.
 */

struct Voxel {
    float r, g, b;      //Cores a serem definidas
    float a;            //a = alpha (indicará o quão transparente o objeto será)
    bool is0n;          //se será incluído ou não
};

/**
 * @brief Classe sculptor.
 */

class Sculptor {
 protected:
 Voxel ***v;
 //matriz 3D
 int nx, ny, nz;    //Dimensao
 float r,g,b,a;

public:
Sculptor (int _nx, int _ny, int _nz);                  //Construtor da classe
~Sculptor();                                           //Destrutor da classe
void SetColor (float r, float g, float b, float alpha);
void PutVoxel (int x, int y, int z);
void CutVoxel (int x, int y, int z);
void PutBox (int x0, int x1, int y0, int y1, int z0, int z1);
void CutBox (int x0, int x1, int y0, int y1, int z0, int z1);
void PutSphere (int xcenter, int ycenter, int zcenter, int radius);
void CutSphere (int xcenter, int ycenter, int zcenter, int radius);
void PutEllipsoid (int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
void CutEllipsoid (int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
void writeOFF(char* filename);
};



#endif // SCULPTOR_H
