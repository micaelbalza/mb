#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include "sculptor.h"
#include "figurageometrica.h"

#include "cutbox.h"
#include "putbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;


int main() {

    ofstream fout;
    ifstream fin;

    fin.open ("matriz.off");  

    vector<string> linhas;
    string linha;
    vector <int>::iterator it;

    while (getline(fin, linha)) {
        linhas.push_back(linha);
    }

    int nx=0, ny=0, nz=0;
    stringstream header(linhas[0]);
    string nome;
    header >> nome;
    header >> nx >> ny >> nz;

    Sculptor t(nx,ny,nz);
    vector<FiguraGeometrica*>v;     //Array de figuras geométricas

    dim 100 100 100
    putSphere 50 50 50 60 1 0 0 1
    cutBox 0 99 1 98 1 98
    putVoxel 50 98 50 1 0 0 1
    putVoxel 50 97 50 1 1 1 1
    putVoxel 50 96 50 1 0 0 1
    putVoxel 50 95 50 1 1 1 1


    /*O formato off no meshlab provê a cor nas formas [0,1] e [0,255], exigindo as cores colocadas na forma fracionária.
    Usa-se <iomanip>, são manipuladores que operam de forma parecida com o printf*/


    /* v interpreta o arquivo da figura e diz qual será a dimensão da figura,
       devolvendo o tamanho da tela e pra cada figura que tenho do interpretador */

    /*---O vetor passará a ser chamado da forma acima pq agora terá qualquer forma que o usuário quiser---*/

   /* Sculptor v(8,8,8);

    v.SetColor(0, 0.7, 0.3, 1);
    v.putVoxel(0,0,0);

    v.SetColor(1, 0, 1, 1);
    v.putVoxel(1,1,1);


    v.SetColor(1, 1, 1, 0.5);
    v.putBox(0,3,1,2,0,3);

    v.SetColor(0, 0, 1, 1);
    v.putSphere(4,4,4,1);

    v.SetColor(1, 0, 1, 1);
    v.putEllipsoid(7,6,6,8,7,7);


    v.cutVoxel(0,0,0);
    v.cutBox(0,3,1,2,0,3);
    v.cutSphere(4,4,4,1);
    v.cutEllipsoid(7,6,6,8,7,7); */

    //v.push_back(new Sculptor);

    for (int i=0; i<linhas.size(); i++) {
        stringstream tipo(linhas[i]);
        tipo >> nome;

        if (nome == "PutVoxel") {
            int x,y,z;
            float r, g, b, a;
            tipo >> x >> y >> z >> r >> g >> b >> a;
            v.push_back(new PutVoxel(x,y,z,r,g,b,a));
        }

        else if (nome == "CutVoxel") {
            int x,y,z;
            tipo >> x >> y >> z;
            v.push_back(new CutVoxel(x,y,z));
        }

        else if (nome == "PutBox") {
            int x0,x1,y0,y1,z0,z1, r, g, b, a;
            tipo >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            v.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }

        else if (nome == "CutBox") {
            int x0,x1,y0,y1,z0,z1;
            tipo >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            v.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
        }

        else if (nome == "PutSphere") {
            int xcenter,ycenter,zcenter, radius;
            float r, g, b, a;
            tipo >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            v.push_back(new PutSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
        }

        else if (nome == "CutSphere") {
            int xcenter,ycenter,zcenter, radius;
            tipo >> xcenter >> ycenter >> zcenter >> radius;
            v.push_back(new CutSphere(xcenter,ycenter,zcenter,radius));
        }

        else if (nome == "PutEllipsoid") {
            int xcenter,ycenter,zcenter, rx,ry,rz;
            float r,g,b,a;
            tipo >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            v.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
        }

        else if (nome == "CutEllipsoid") {
            int xcenter,ycenter,zcenter,rx,ry,rz;
            tipo >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            v.push_back(new CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
        }
    }


    for (int i=0; i<v.size(); i++) {
        v[i] -> draw(t);
    }

    t.writeOFF ("matriz.off");
    fin.close();

    return 0;
}
