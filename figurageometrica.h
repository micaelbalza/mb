#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"
#include <iostream>

/**
  @brief Classe abstrata FiguraGeometrica
  */

/*FiguraGeometrica é uma classe abstrata, servindo para representar objetos primitivos genéricos.*/

class FiguraGeometrica
{
    /* Não será preciso fazer um void virtual para as cores.*/
public:
    FiguraGeometrica();
       virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t)=0;   //Será a função virtual pura pois ela se iguala a zero.

};

/* A função virtual draw(Sculptor &t) existe para ser chamada pelas outras subclasses */

#endif // FIGURAGEOMETRICA_H
