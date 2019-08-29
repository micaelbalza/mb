#include <stdio.h>
#include <stdlib.h>
int main()
{
    char   vetor1[4];
    int    vetor2[4];
    float  vetor3[4];
    double vetor4[4];

    printf (" Usando char: \n");
    for (int i=0; i<=3; i++) {
        printf("%d\n", (vetor1+i));
    }
        printf (" Tamanho em bytes: %d\n", sizeof(char));


    printf ("\n Usando int: \n");
    for (int i=0; i<=3; i++) {
        printf("%d\n", (vetor2+i));
    }
        printf (" Tamanho em bytes: %d\n", sizeof(int));

    printf ("\n Usando float: \n");
    for (int i=0; i<=3; i++) {
        printf("%d\n", (vetor3+i));
    }
        printf (" Tamanho em bytes: %d\n", sizeof(float));

    printf ("\n Usando double: \n");
    for (int i=0; i<=3; i++) {
        printf("%d\n", (vetor4+i));
    }
        printf (" Tamanho em bytes: %d\n", sizeof(double));

        return 0;
}

/*
SAIDA DO PROGRAMA: 

 Usando char: 
1334232212
1334232213
1334232214
1334232215
 Tamanho em bytes: 1     // --- Igual ao da questao 10

 Usando int: 
1334232144
1334232148
1334232152
1334232156
 Tamanho em bytes: 4     // --- Diferente do int da questao 10 que ocupa 2 bytes

 Usando float: 
1334232160
1334232164
1334232168
1334232172
 Tamanho em bytes: 4     // --- Igual ao da questao 10

 Usando double: 
1334232176
1334232184
1334232192
1334232200
 Tamanho em bytes: 8     // --- Igual ao da questao 10



*/






