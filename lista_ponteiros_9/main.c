#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vetor[]= {4,9,13};
    for (int i=0; i<=2; i++) {
        printf("%d\n", *(vetor+i));
    }

    //A função acima vai retornar os valores contidos nos vetores,
    //pois *(vetor+i) é uma forma de representar vetor[i] em forma de ponteiros

    for (int i=0; i<=2; i++) {
        printf("%d\n", vetor+i);
    }

    //Por outro lado, esta última função irá retornar o endereço dos bits cedidos
    //Como cada bit possui 4 bytes, a cada nº novo do vetor, 4 de espaço eram cedidos

    return 0;
}
