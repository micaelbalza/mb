#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#include "figurageometrica.h"

using namespace std;

FiguraGeometrica::FiguraGeometrica()
{
    id= 0;
}

FiguraGeometrica::~FiguraGeometrica() {

}

void FiguraGeometrica::draw(Sculptor &t) {

}



//_______________________________PutVoxel__________________________________
/**
 * @brief Ativa o voxel na posição x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui os mesmos
 * à cor atual do desenho.
 */

PutVoxel::PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a)
{
    x=_x; y=_y; z=_z;
    r=_r; g=_g; b=_b; a=_a;

}

/*PutVoxel::~PutVoxel() {

} */

void PutVoxel::draw(Sculptor &t) {
    t.SetColor(r,g,b,a);
    t.PutVoxel(x,y,z);
}


//_______________________________CutVoxel__________________________________

/**
 * @brief Desativa o voxel na posição x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] fazendo IsOn=false
 */

CutVoxel::CutVoxel(int _x, int _y, int _z)
{
    x=_x; y=_y; z=_z;
}

CutVoxel::~CutVoxel(){

}

void CutVoxel::draw (Sculptor &t) {
    t.CutVoxel(x,y,z);
}


//_______________________________PutBox__________________________________
/**
 * @brief Ativa todos os voxels na posição x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui os mesmos
 * à cor atual do desenho.
 * * Será desenhado um paralelepípedo com intervalos delimitados nas três dimensões
   e com suas respectivas cores
 */



PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a)
{
    x0=_x0; x1=_x1;
    y0=_y0; y1=_y1;
    z0=_z0; z1=_z1;
    r=_r; g=_g; b=_b; a=_a;
}

PutBox::~PutBox() {

}

void PutBox::draw(Sculptor &t) {
    t.SetColor(r,g,b,a);
    int i=x0; int j=y0; int k=z0;
    for (i;i<x1;i++) {
        for (j;j<y1;j++) {
            for (k;k<z1;k++) {
                t.PutVoxel(i,j,k);
            }
        }
    }
}



//_______________________________CutBox__________________________________

/** @brief Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
 * e atribui aos mesmos a cor atual de desenho
 */


CutBox::CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1)
{
    x0=_x0; x1=_x1;
    y0=_y0; y1=_y1;
    z0=_z0; z1=_z1;
}

CutBox::~CutBox() {

}

void CutBox::draw(Sculptor &t) {

    int i=x0; int j=y0; int k=z0;
    for (i;i<x1;i++) {
        for (j;j<y1;j++) {
            for (k;k<z1;k++) {

                /*i percorrerá entre os intervalos atribuidos a x0 e x1
                  j entre y0 e y1 e k entre z0 e z1 para apagar um paralelepípedo  */

                t.CutVoxel(i,j,k);

            }
        }
    }
}


//_______________________________PutSphere__________________________________

/**
 * @brief Ativa todos os voxels que satisfazem à equação da esfera e
 * atribui aos mesmos a cor atual de desenho (r,g,b,a)
 */

PutSphere::PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;

    r=_r; g=_g; b=_b; a=_a;

}

PutSphere::~PutSphere() {

}

void PutSphere::draw(Sculptor &t) {
   // t.SetColor(r,g,b,a);
    //int i=0; int j=0; int k=0;
    for(int i = xcenter-radius; i<=xcenter+radius; i++){
        for(int j = ycenter-radius; j<=ycenter+radius; j++){
            for(int k = zcenter-radius; k<=zcenter+radius; k++){
                if((i-xcenter)^2+(j-ycenter)^2+(k-zcenter)^2 <= (radius)^2) {
                    t.SetColor(r,g,b,a);
                    t.PutVoxel(i,j,k);
                }
            }
        }
    }

}


//_______________________________CutSphere__________________________________


/** @brief Desativa todos os voxels que satisfazem à equação da esfera
*/


CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}

CutSphere::~CutSphere(){

}

void CutSphere::draw(Sculptor &t) {
  /*  int i=0; int j=0; int k=0;
    for (i; i<nx; i++) {
        for (j; j<ny; j++) {
            for (k; k<nz; k++) {
                if((i-xcenter)^2+(j-ycenter)^2+(k-zcenter)^2 <= (radius)^2) {
                    t.CutVoxel(i,j,k);
                }
            }
        }
    }*/

    for(int i = xcenter-radius; i<=xcenter+radius; i++){
        for(int j = ycenter-radius; j<=ycenter+radius; j++){
            for(int k = zcenter-radius; k<=zcenter+radius; k++){
                if((i-xcenter)^2+(j-ycenter)^2+(k-zcenter)^2 <= (radius)^2) {
                    t.CutVoxel(i,j,k);
                }
            }
        }
    }

}

//_______________________________PutEllipsoid__________________________________

/** @brief Ativa todos os voxels que satisfazem à equação do elipsóide e atribui
 * aos mesmos a cor atual de desenho  */

PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx=_rx; ry=_ry; rz=_rz;
    r = _r; g = _g; b = _b; a = _a;
}

PutEllipsoid::~PutEllipsoid() {

}

void PutEllipsoid::draw(Sculptor &t) {
    t.SetColor(r,g,b,a);
    int i=0; int j=0; int k=0;
    for (i; i<rx; i++) {
       for (j; j<ry; j++) {
           for (k; k<rz; k++) {
              if(((pow((i - xcenter),2)/(float)pow(rx,2) + (pow((j - ycenter),2))/(float)pow(ry,2) + (pow((k - zcenter),2))/(float)pow(rz,2)) <= 1))
              {
                    t.PutVoxel(i,j,k);
               }
            }
        }
    }

}


//_______________________________CutEllipsoid__________________________________

/** @brief Desativa todos os voxels que satisfazem à equação do elipsóide */

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx=_rx; ry=_ry; rz=_rz;
}

CutEllipsoid::~CutEllipsoid() {

}

void CutEllipsoid::draw(Sculptor &t) {
    int i=0; int j=0; int k=0;
    for (i; i<rx; i++) {
       for (j; j<ry; j++) {
           for (k; k<rz; k++) {
              if(((pow((i - xcenter),2)/(float)pow(rx,2) + (pow((j - ycenter),2))/(float)pow(ry,2) + (pow((k - zcenter),2))/(float)pow(rz,2)) <= 1))
              {
                    t.CutVoxel(i,j,k);
               }
            }
        }
    }

}


vector<string> split_string(string s){
    vector<string> tokens;
    size_t pos = 0;
    while (true)
    {
        pos = s.find(' ');
        if (pos == string::npos)
        {
            tokens.push_back(s.substr(0, s.size()));
            break;
        }
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);

    }

    return tokens;
}


Sculptor* load_sculpt_from_file(const char* filename)
{
    vector<string> commands;

    Sculptor* sculpt = nullptr;
    ifstream infile(filename);
    string linha;
    while (getline(infile, linha))
    {
        istringstream iss(linha);
        commands.push_back(linha);
    }
    infile.close();

    vector<string>first_comm_args = split_string(commands[0]);
    vector<FiguraGeometrica *> fgs;

    for (size_t i=0; i < commands.size(); i++)
    {
        vector<string>comm_args = split_string(commands[i]);

        // command
        if(comm_args[0].compare("dim") == 0)
        {
            int largura = atoi( comm_args[1].c_str() );
            int altura = atoi( comm_args[2].c_str() );
            int profundidade = atoi( comm_args[3].c_str() );
            if (sculpt != nullptr)
            {
                delete sculpt;
            }
            sculpt = new Sculptor(largura, altura, profundidade);
        }
        else if(comm_args[0].compare("putvoxel") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int y0 = atoi( comm_args[2].c_str() );
            int z0 = atoi( comm_args[3].c_str() );

            float r = atof( comm_args[4].c_str() );
            float g = atof( comm_args[5].c_str() );
            float b = atof( comm_args[6].c_str() );
            float a = atof( comm_args[7].c_str() );
            fgs.push_back( new PutVoxel(x0, y0, z0, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutvoxel") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int y0 = atoi( comm_args[2].c_str() );
            int z0 = atoi( comm_args[3].c_str() );
            fgs.push_back( new CutVoxel(x0, y0, z0)  );
        }
        else if(comm_args[0].compare("putbox") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int x1 = atoi( comm_args[2].c_str() );
            int y0 = atoi( comm_args[3].c_str() );
            int y1 = atoi( comm_args[4].c_str() );
            int z0 = atoi( comm_args[5].c_str() );
            int z1 = atoi( comm_args[6].c_str() );


            float r = atof( comm_args[7].c_str() );
            float g = atof( comm_args[8].c_str() );
            float b = atof( comm_args[9].c_str() );
            float a = atof( comm_args[10].c_str() );
            fgs.push_back( new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutbox") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int x1 = atoi( comm_args[2].c_str() );
            int y0 = atoi( comm_args[3].c_str() );
            int y1 = atoi( comm_args[4].c_str() );
            int z0 = atoi( comm_args[5].c_str() );
            int z1 = atoi( comm_args[6].c_str() );
            fgs.push_back( new CutBox(x0, x1, y0, y1, z0, z1)  );
        }
        else if(comm_args[0].compare("putsphere") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int radius = atoi( comm_args[4].c_str() );


            float r = atof( comm_args[5].c_str() );
            float g = atof( comm_args[6].c_str() );
            float b = atof( comm_args[7].c_str() );
            float a = atof( comm_args[8].c_str() );
            fgs.push_back( new PutSphere(xc, yc, zc, radius, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutsphere") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int radius = atoi( comm_args[4].c_str() );
            fgs.push_back( new CutSphere(xc, yc, zc, radius)  );
        }
        else if(comm_args[0].compare("putellipsoid") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int rx = atoi( comm_args[4].c_str() );
            int ry = atoi( comm_args[5].c_str() );
            int rz = atoi( comm_args[6].c_str() );


            float r = atof( comm_args[7].c_str() );
            float g = atof( comm_args[8].c_str() );
            float b = atof( comm_args[9].c_str() );
            float a = atof( comm_args[10].c_str() );
            fgs.push_back( new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutellipsoid") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int rx = atoi( comm_args[4].c_str() );
            int ry = atoi( comm_args[5].c_str() );
            int rz = atoi( comm_args[6].c_str() );
            fgs.push_back( new CutEllipsoid(xc, yc, zc, rx, ry, rz)  );

        }
        else
        {
            cout << "invalid command" << endl;
        }

    }

    if(sculpt != nullptr)
    {
        for(size_t i=0; i < fgs.size(); i++)
        {
            fgs[i]->draw(*sculpt);
        }
    }
    return sculpt;
}




