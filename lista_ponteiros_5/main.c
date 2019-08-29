#include <stdio.h>

int main()
{
    int valor, *p1;
    float temp, *p2;
    char aux;
    char *nome = "Ponteiros";
    char *p3;
    int idade, vetor[3], *p4, *p5;

    /* (a) */
    valor = 10;
    p1 = &valor;
    *p1 = 20;
    printf("%d \n", valor);

    //Foi exibido 20, já que o conteúdo do valor foi modificado de 10 para 20

    /* (b) */
    temp = 26.5;
    p2 = &temp;
    *p2 = 29.0;
    printf("%.1f \n", temp);

    //Assim como (a), (b) passou por uma modificação de conteúdo, exibindo 29

    /* (c) */
    p3 = &nome[0];
    aux = *p3;
    printf("%c \n", aux);

    //Foi exibido o primeiro vetor da palavra "Ponteiros", já que p3 recebia inicialmente o endereço da variável nome[0]
    //A variável auxiliar receberia o conteúdo presente nesse endereço, na qual o programa lê a letra "P"

    /* (d) */
    p3 = &nome[4];
    aux = *p3;
    printf("%c \n", aux);

    //Em um processo similar à letra (c), agora p3 recebe o endereço no 5º vetor da variável nome (&nome[4])
    //Com aux recebendo seu conteúdo, foi retornado a letra "e"

    /* (e) */
    p3 = nome;
    printf("%c \n", *p3);

    //*p3 retorna a letra "P"

    /* (f) */
    p3 = p3 + 4;
    printf("%c \n", *p3);

    //*p3 passa a retornar a letra "e", já que a variável passa a ser somado mais 4 ("e" se localiza
    //na quinta posição)

    /* (g) */
    p3--;
    printf("%c \n", *p3);

    //*p3 passa a ter um valor reduzido a -1 (p3-- = p3= p3-1) pra letra "t" de "Ponteiros"

    /* (h) */
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor;
    idade = *p4;
    printf("%d \n", idade);

    //p4 reconhece o primeiro vetor (vetor[0]), adotando-o como variável
    //Quando o seu conteúdo é lido por idade, ele reconhecerá apenas seu valor (31)

    /* (i) */
    p5 = p4 + 1;
    idade = *p5;
    printf("%d \n", idade);

    //p5 passa a ler a posição de p4 + 1, onde chega a vetor[1]
    //Reconhecendo como idade o valor 45

    /* (j) */
    p4 = p5 + 1;
    idade = *p4;
    printf("%d \n", idade);

    //p4 passa a reconhecer p5 somado a +1 posição
    //Com isso, quando idade pega o seu conteúdo, passará a ler o valor 27

    /* (l) */
    p4 = p4 - 2;
    idade = *p4;
    printf("%d \n", idade);

    //Ao reduzir -2, a variável idade voltará a ler o conteúdo de vetor[0]
    //Imprimindo 31

    /* (m) */
    p5 = &vetor[2] - 1;
    printf("%d \n", *p5);

    //p5 lê o endereço de vetor[2] - 1, quando *p5 é imprimido, seu conteúdo (reduzido para o vetor[1])
    //Será impresso, no caso, 45

    /* (n) */
    p5++;
    printf("%d \n", *p5);

    //p5 é somado +1, lendo assim a posição de vetor[2] quando o seu conteúdo for impresso

    return 0;
}
