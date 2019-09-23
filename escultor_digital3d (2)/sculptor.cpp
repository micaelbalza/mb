#include <iostream>
#include <cmath>
#include <cstdlib>
#include<string>
#include <fstream>
#include "sculptor.h"

/* v[x][y][z].r=r;
   v[x][y][z].g=g;
   v[x][y][z].b=b;
   v[x][y][z].a=a;
*/

/* Implementando o setColor no cpp
void Sculptor::setColor(float r, float g, float b, float a) {

    //pra diferenciar o r global (header) do local (do cpp)
    this -> r=r;   //("r" do sculptor = variável local)

    this -> g = g;
    this -> b = b;
    a = alpha;
   }
*/

/* Equação do elipsóide ((x-xc)^2)/(rx)^2 */
using namespace std;

/**
 * @brief Construtor da classe
 */

Sculptor::Sculptor (int _nx, int _ny, int _nz) {
    nx=_nx; ny= _ny; nz=_nz;

    //Alocando v


    v = new Voxel**[nx];
               if(v == nullptr) // teste de alocação
               {
                   exit(0);
               }

     v[0] = new Voxel*[nx*ny];


               if(v[0] == nullptr)
               {
                   exit(0);  // teste de alocação
               }


      v[0][0] = new Voxel[nx*ny*nz];


               if(v[0][0] == nullptr)
               {
                   exit(0);// teste de alocação
               }




        for(int i = 1; i<nx; i++){
          v[i] = v[i-1] + ny;   // alinha as linhas com colunas da matriz
           }                     //


        for(int i = 1; i<ny*nz; i++){
          v[0][i] = v[0][i-1] + nz; //
          }




    for (int i=0; i<nx; i++) {
        for (int j=0; j<ny; j++) {
            for (int k=0; k<nz; k++) {
               v[i][j][k].is0n=false;
            }
        }
    }
}

/**
 * @brief Destrutor da classe
 */

Sculptor::~Sculptor () {
    delete [] v[0][0]; // delete planos
    delete [] v[0];    // delete colunas
    delete [] v;       // delete linhas/vetor
}

/**
 * @brief Define a cor atual do desenho
 */

void Sculptor::SetColor(float r, float g, float b, float alpha) {

    //pra diferenciar o r global (header) do local (do cpp)
    this -> r = r;   //("r" do sculptor = variável local)
    this -> g = g;
    this -> b = b;
    a= alpha;

}

/**
 * @brief Ativa o voxel na posição (x, y, z) (fazendo is0n=true) e
 * atribui o mesmo à cor atual do desenho
 */

void Sculptor::putVoxel (int x, int y, int z) {

                 v[x][y][z].is0n=true;
                 v[x][y][z].r=r;
                 v[x][y][z].g=g;
                 v[x][y][z].b=b;
                 v[x][y][z].a=a;
}

/**
 * @brief Desativa o voxel na posição (x, y, z) (fazendo is0n=false)
 */

void Sculptor::cutVoxel (int x, int y, int z) {

    v[x][y][z].is0n=false;
}

/**
 * @brief Ativa todos os voxels na posição x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui os mesmos
 * à cor atual do desenho.
 */

void Sculptor::putBox (int x0, int x1, int y0, int y1, int z0, int z1) {

    /* Será desenhado um paralelepípedo com intervalos delimitados nas três dimensões
       e com suas respectivas cores */
    int i=x0;
    int j=y0;
    int k=z0;
    for (i;i<x1;i++) {
        for (j;j<y1;j++) {
            for (k;k<z1;k++) {
                //Modificado de v[x][y][z] para v[i][j][k]
                v[i][j][k].is0n=true;
                v[i][j][k].r=r;
                v[i][j][k].g=g;
                v[i][j][k].b=b;
                v[i][j][k].a=a;
            }
        }
    }
}

/** @brief Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
 * e atribui aos mesmos a cor atual de desenho
 */

void Sculptor::cutBox (int x0, int x1, int y0, int y1, int z0, int z1) {

    int i=x0;
    int j=y0;
    int k=z0;
    for (i;i<x1;i++) {
        for (j;j<y1;j++) {
            for (k;k<z1;k++) {
                //void SetColor (float r, float g, float b, float alpha);

                /*i percorrerá entre os intervalos atribuidos a x0 e x1
                  j entre y0 e y1 e k entre z0 e z1 para apagar um paralelepípedo  */

                v[i][j][k].is0n=false;

            }
        }
    }
}

/**
 * @brief Ativa todos os voxels que satisfazem à equação da esfera e
 * atribui aos mesmos a cor atual de desenho (r,g,b,a)
 */

void Sculptor::putSphere (int xcenter, int ycenter, int zcenter, int radius) {
    /*this -> xcenter; this -> ycenter;
    this -> zcenter; this -> radius; */
    int i=0;
    int j=0;
    int k=0;
    for (i; i<nx; i++) {
        for (j; j<ny; j++) {
            for (k; k<nz; k++) {
                if((i-xcenter)^2+(j-ycenter)^2+(k-zcenter)^2 <= (radius)^2) {
                    //void SetColor (float r, float g, float b, float alpha);
                    v[i][j][k].is0n=true;
                    v[i][j][k].r=r;
                    v[i][j][k].g=g;
                    v[i][j][k].b=b;
                    v[i][j][k].a=a;

                }
            }
        }
    }
}

/** @brief Desativa todos os voxels que satisfazem à equação da esfera
*/

void Sculptor::cutSphere (int xcenter, int ycenter, int  zcenter, int radius) {
  /*  this -> xcenter; this -> ycenter;
    this -> zcenter; this -> radius;
    if (is0n == false) {
       v[x][y][z] = (new Sphere (xcenter, ycenter, zcenter, radius));
    } */
    int i=0;
    int j=0;
    int k=0;
    for (i; i<nx; i++) {
        for (j; j<ny; j++) {
            for (k; k<nz; k++) {
                if((i-xcenter)^2+(j-ycenter)^2+(k-zcenter)^2 <= (radius)^2) {
                 v[i][j][k].is0n=false;
                }
           }
        }
      }
}

/** @brief Ativa todos os voxels que satisfazem à equação do elipsóide e atribui
 * aos mesmos a cor atual de desenho  */

void Sculptor::putEllipsoid (int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
   /* if (is0n == true) {
       v[x][y][z]  = (new Ellipsoid (xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
    } */

    /* Equação geral do elipsóide: ((x²/a²)+(y²/b²)+(z²/c²)=1) */

    int i=0;
    int j=0;
    int k=0;
    for (i; i<rx; i++) {
       for (j; j<ry; j++) {
           for (k; k<rz; k++) {
              if(((pow((i - xcenter),2)/(float)pow(rx,2) + (pow((j - ycenter),2))/(float)pow(ry,2) + (pow((k - zcenter),2))/(float)pow(rz,2)) <= 1)){
                    v[i][j][k].is0n=true;
                    v[i][j][k].r=r;
                    v[i][j][k].g=g;
                    v[i][j][k].b=b;
                    v[i][j][k].a=a;
                }
            }
        }
    }

}

/** @brief Desativa todos os voxels que satisfazem à equação do elipsóide */

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

    int i=0;
    int j=0;
    int k=0;
    for (i; i<rx; i++) {
       for (j; j<ry; j++) {
           for (k; k<rz; k++) {
              if(((pow((i - xcenter),2)/(float)pow(rx,2) + (pow((j - ycenter),2))/(float)pow(ry,2) + (pow((k - zcenter),2))/(float)pow(rz,2)) <= 1)){
                   v[i][j][k].is0n=false;
              }
           }
       }
    }
}


//______________________________________________________________________________________________________________***********________

void Sculptor::writeOFF (char *filename) {


}
