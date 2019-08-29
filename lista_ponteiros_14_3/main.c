#include <stdio.h>
#include <stdlib.h>

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

    ord=num_componentes;    //ord representa a ordenação dos vetores

    while (ord > num_componentes) {
    for (i=0; i<num_componentes; i++) {

        if (v[i] > v[i+1]) {
            troca = v[i+1];
            v[i+1] = v[i];
            v[i+1] = troca;
        }

        if (v[i] < v[i+1]) {
            troca = v[i];
            v[i] = v[i+1];
            v[i] = troca;
        }
     }
    ord=ord-1;
    }
        printf("Os numeros em ordem crescente sao:\n");
        for (i=0; i<num_componentes; i++) {
            printf("%.2f\n", v[i]);
        }

        free(v);

    return 0;
}
