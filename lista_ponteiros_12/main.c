#include <stdio.h>

int main()
{
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;
//--------

   aloha[2] = value;  //  Valido   a posicao 3 do vetor de float aloha recebe o lavor de value(2.2)

   scanf("%f", &aloha);  // valido  , leitura apenas do elemento indice 0 da matriz(onde se encontra o end iniciaL)

   aloha = value"; // invalido  , expressao sem idexaçao da posiçao/mal formada com aspas ao final.

   rintf("%f", aloha); // invalido   , aloha é um ponteiro pra float, enquanto a função printf com "%f" está configurada para exibir um double/float , e nao um ponteiro para float

   coisas[4][4] = aloha[3]; // Valido    , a posicao 4x4 da matriz de float 'coisas' recebe o conteudo da posicao 3 do vetor de float 'aloha'

   coisas[5] = aloha; // invalido      , querendo atribuir um ponteiro para float a uma matriz para float

   pf = value; // Invalido      , atribuiçao mal formada, querendo atribuir um float a um ponteiro(ao invez de passar o seu endereço)

   pf = aloha; // Valido      , atribuindo ao ponteiro pf o valor salvo no ponteiro aloha(vetor de float).

    return 0;
}
