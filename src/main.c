#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int *geraVetor(int n)
{
    int *vetor = malloc(n * sizeof(int));

    srand(time(NULL));

    if (vetor == NULL)
    {
        printf("Erro na alocação de memoria.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 10; i++) {
        vetor[i] = rand() % 100;
    }

    return vetor;
}

int main(int argc, char const *argv[])
{
    int *vetor = geraVetor(10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", vetor[i]);
    }

    return 0;
}
