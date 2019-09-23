#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sculptor.h"

using namespace std;


int main() {

    ofstream fout;
    ifstream fin;

    //fin.open ("/home/carlosmiranda/Documentos/2019.2 - Programação Avançada/projeto/escultor_digital3d/matriz.vect");


    Sculptor v(8,8,8);

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
    v.cutEllipsoid(7,6,6,8,7,7);

    return 0;
}
