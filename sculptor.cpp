#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
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

void Sculptor::PutVoxel (int x, int y, int z) {

                 v[x][y][z].is0n=true;
                 v[x][y][z].r=r;
                 v[x][y][z].g=g;
                 v[x][y][z].b=b;
                 v[x][y][z].a=a;
}

/**
 * @brief Desativa o voxel na posição (x, y, z) (fazendo is0n=false)
 */

void Sculptor::CutVoxel (int x, int y, int z) {

    v[x][y][z].is0n=false;
}

//______________________________________________________________________________________________________________***********________

void Sculptor::writeOFF (char* filename) {
    int n_voxel=0;

    /* Para verificar o seu voxel e seu arredor */
    int aux[nx][ny][nz];
    bool test_x, test_y, test_z;

    for(int i = 0; i < nx; i++){
           for(int j = 0; j < ny; j++){
               for(int k = 0; k < nz; k++){
                   aux[i][j][k] = 0;
               }
           }
    }

    ofstream fout (filename);
    fout<<"OFF"<<endl;

    for(int i = 0; i < nx-2; i++) {
      for(int j = 0; j < ny-2; j++) {
         for(int k = 0; k < nz-2; k++) {
             test_x = false, test_y = false, test_z=false;

             //Verificacao ao redor do voxel
              if(v[i][j][k].is0n && v[i+2][j][k].is0n){
                   test_x = true;
               }

              if(v[i][j][k].is0n && v[i][j+2][k].is0n){
                   test_y = true;
               }

              if(v[i][j][k].is0n && v[i][j][k+2].is0n){
                   test_z = true;
                   }

              if(test_x || test_y || test_z){
                   aux[i+1][j+1][k+1] = 1;
                   }
               }
           }
       }

    for(int i = 0; i < nx; i++){
       for(int j = 0; j < ny; j++){
          for(int k = 0; k < nz; k++){
               if (v[i][j][k].is0n && aux[i][j][k] == 0){
                        n_voxel++;
                   }
                }
            }
       }

  fout << 8*n_voxel << " " << 6*n_voxel << " " << 0 << std::endl;

     for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
           for(int k = 0; k < nz; k++){
               if (v[i][j][k].is0n && aux[i][j][k] == 0){
                        fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                        fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                        fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                        fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                        fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                        fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                        fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                        fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    }
           }
        }
     }

     for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
           for(int k = 0; k < nz; k++){
              if (v[i][j][k].is0n && aux[i][j][k] ==0){
                   fout << 4 << " " << 0 + 8*i << " " << 3 + 8*i << " " << 2 + 8*i << " " << 1 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                   fout << 4 << " " << 4 + 8*i << " " << 5 + 8*i << " " << 6 + 8*i << " " << 7 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                   fout << 4 << " " << 0 + 8*i << " " << 1 + 8*i << " " << 5 + 8*i << " " << 4 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                   fout << 4 << " " << 0 + 8*i << " " << 4 + 8*i << " " << 7 + 8*i << " " << 3 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                   fout << 4 << " " << 3 + 8*i << " " << 7 + 8*i << " " << 6 + 8*i << " " << 2 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                   fout << 4 << " " << 1 + 8*i << " " << 2 + 8*i << " " << 6 + 8*i << " " << 5 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                   }
           }
        }
     }


}
