#ifndef ESCULTOR_H
#define ESCULTOR_H

struct Voxel {
    float r, g, b;      //Cores a serem definidas
    float a;            //a = alpha (indicará o quão transparente o objeto será)
    bool is0n;          //se será incluído ou não
};

class Sculptor {
 protected:
 Voxel ***v;
 //3D matrix
 int nx, ny, nz;    //Dimensions
 float r,g,b,a;     //Current drawing color

public:
Sculptor (int _nx, int _ny, int _nz);                  //Construtor da classe
~Sculptor();                                           //Destrutor da classe
void SetColor (float r, float g, float b, float alpha);
void putVoxel (int x, int y, int z);
void cutVoxel (int x, int y, int z);
void putBox (int x0, int x1, int y0, int y1, int z0, int z1);
void cutBox (int x0, int x1, int y0, int y1, int z0, int z1);
void putSphere (int xcenter, int ycenter, int zcenter, int radius);
void cutSphere (int xcenter, int ycenter, int zcenter, int radius);
void putEllipsoid (int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
void cutEllipsoid (int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
void writeOFF(string filename);
void writeVECT (string filename);
};



#endif // ESCULTOR_H
