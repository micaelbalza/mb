#include <stdio.h>

int main()
{


    int i,j; //declaracao de variaveis inteiras
    int *p,*q;  // declaracao de ponteiros para inteiros


p = i;  // atribuiao ilegal, um ponteiro nao recebe o valor do inteiro i
// um ponteiro recebe o endereço da variavel na qual ele aponta

q = &j; // OK     ponteiro q recebendo o endereco de 'j'

p = &*&i; // OK atribuindo a p o endereco de da desreferenciação do endereço de i

i = (*&)j; // atribuicao ilegal, colocando como prioridade 2 operadores sem antes atribuir a qual variavel deseja-se trabalhar.

i = *&j; // OK , atribuindo a i o valor que consta no end de j, ou seja, j

i = *&*&j; // OK , atribuindo  a i o valor que consta em j por meio da desreferenciacao e e endereço

q = *p; // atribuiçao ilegal, tentando gravar em um ponteiro um dado do tipo inteiro (pois está pegando a desref. do ponteiro p)

i = (*p)++ + *q;  // OK , atribuindo a i a soma de inteiros passados por referencia


    return 0;
}




