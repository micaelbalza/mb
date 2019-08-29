#include <stdio.h>

int main()
{
    int i=5, *p;
    p = &i;
    printf ("%x %x %d %d %d", p, *p+2, **&p, 3**p, **&p+4);
    return 0;
}

// p armazena o endereço contido em i (no caso, edde358 no programa, ou 4094 na questão)
// *p+2 é o conteúdo de p (no caso, o valor de i=5) somado mais 2 (5+2 = 7)
// **&p transforma o endereço de p no valor que foi atribuído a i (5)
// 3**p é o produto de 3 com conteúdo de p (3*5 = 15)
// **&p é a soma do valor atribuido a i mais 4 (5 + 4 = 9)
