#include <stdio.h>
#include <stdlib.h>
int main()
{
    double vetor[4];

    for (int i=0; i<=3; i++) {
        printf("%d\n", *(vetor+i));
    }

/*
Resposta: 
O endereco inicial de 'TIPOx[4]' está na posicao 4092 da memoria


--Char:
o tipo char ocupa 1 byte, ou seja, somar um inteiro a o endereco inicial do vetor soma 'inteiros' bytes.
	x+1= 4092 + 1byte  = 4093
	x+2= 4092 + 2byte  = 4094
	x+3= 4092 + 3byte  = 4095

--int:
o tipo char ocupa 2 byte, ou seja, somar um inteiro a o endereco inicial do vetor soma 'inteiros' 2bytes.
	x+1= 4092 + 2byte  = 4094
	x+2= 4092 + 4byte  = 4096
	x+3= 4092 + 6byte  = 4098

--float:
o tipo char ocupa 4 byte, ou seja, somar um inteiro a o endereco inicial do vetor soma 'inteiros' 4bytes.
	x+1= 4092 + 4byte  = 4096
	x+2= 4092 + 8byte  = 4100
	x+3= 4092 + 12byte = 4104

 --double:
o tipo char ocupa 8 byte, ou seja, somar um inteiro a o endereco inicial do vetor soma 'inteiros' 8bytes.
	x+1= 4092 + 8byte  = 4100
	x+2= 4092 + 16byte = 4108
	x+3= 4092 + 24byte = 4116







*/





    //Se o vetor for declarado como char sem dizer seus valores, ele irá retornar 0 em todas as posições
    //Se o vetor estiver em float, em cada valor retornará -1574191768; 38989424; 38989424; 38989424
    //Se o vetor estiver em double, retornará 286054024; 24575600; 24575600; 24575600



    return 0;
}
