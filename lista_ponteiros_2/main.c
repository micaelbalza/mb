#include <stdio.h>

int main()
{
    int i=3, j=5;
    int *p, *q;
    p = &i;
    q = &j;

    printf ("%d\n", p==&i);         //Ele compara p com &i, como p=&i, ele é verdadeiro (valor 1)
    printf ("%d\n", *p - *q);       //Seu resultado será -2 (3-5 = 2)
    printf ("%d\n", **&p);          //**&p converte o endereço no conteúdo atribuido a ele antes (no caso, 3)
    printf ("%d\n", 3 - *p/(*q) +7);

    /*O último printf será um valor inteiro (10) porque todas as variáveis foram declaradas como inteiros */

    return 0;
}
