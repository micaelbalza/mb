#include <stdio.h>
#include <stdlib.h>
// Funcao que compara 2 valores e retorna um inteiro
// 2 parametros passados por referencia(na forma const para que nao sejam alterados acidentalmente)
int comparador(const void *a, const void *b) {
   if (*(int*)a > *(int*)b) {
      return 1; // compara se A é maior que B e retorna 1 caso verdadeiro.
   } else if (*(int*)a < *(int*)b) {
      return -1;// compara se A é menor que B e retorna -1 caso verdadeiro.
   } else {
      return 0; // caso os valores sejam iguais retorna 0.
   }
}

int main()
{
    int num_componentes, i, ord;
    float *v, troca;

    printf("Digite quantos numeros voce deseja:\n");
    scanf("%d", &num_componentes);

    v=(float*) malloc(num_componentes*sizeof(float));

    for (i=0; i<num_componentes; i++) {
        printf("Digite o valor %d:",i+1);
        scanf("%f", &v[i]);
    }

    // -------- parte implementada para o qsort --------------
    //A função qsort recebe 4 parametros, um ponteiro que indica o vetor
    // a quantidade de membros do vetor, o tamanho do seu tipo, e um
    //ponteiro do tipo função para comparar os dados e retornar
    // certos valores determinados para escolha de posiçoes.

    qsort(v, num_componentes, sizeof (float), comparador);
    // a funçao sizeof faz uso da comparador para tomada de decisao
    //dessa forma a funçao qsort é eficaz a varios tipos de dados, desde que lhe "ensine" por meio
    //de outra funçao como ordenar o vetor
    // -------- parte implementada para o qsort --------------



    // impressao do vetor ordenado ------------------
    printf("Os numeros em ordem crescente sao:\n");
        for (i=0; i<num_componentes; i++) {
            printf("%.2f\n", v[i]);
        }

        free(v);

    return 0;
}
