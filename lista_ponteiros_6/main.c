#include <stdio.h>
#include <stdlib.h>


int main()
{
    float vet[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float *f;
    f = vet;
    printf ("contador/valor/valor/endereco/endereco");

    for (int i=0; i<=4; i++) {
        printf("\ni = %d\n", i);
        printf("vet[%d] = %.1f\n",i,vet[i]);
        printf("*(f+%d)= %.1f\n", i, *(f+i));
        printf("&vet[%d] = %X\n",i, &vet[i]);
        printf("(f+%d) = %X\n",i, f+i);
    }

    /*Foi exibido de forma respectiva o contador, o valor (na forma de vetor (vet[i]) e na
     * forma de ponteiro (*(f+i)) e o endereço, através dos ponteiros, conforme
     * a questão desejava */
    return 0;
}
