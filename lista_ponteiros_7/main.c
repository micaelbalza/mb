#include <stdio.h>
#include <stdlib.h>
int main()
{
    int pulo[3];
    printf("%d\n", *(pulo));
    printf("%d\n", *pulo+2);
    printf("%d\n", *(pulo+4));
    printf("%d\n", pulo+2);
    printf("%d\n", pulo+4);

    //Assumindo que pulo[] é um vetor do tipo int,
    //quais das seguintes expressões referenciam o valor do terceiro elemento do vetor?

    //A resposta é *(pulo+2), pois 2 corresponde ao terceiro vetor e o * capta o conteúdo dele
    return 0;
}
