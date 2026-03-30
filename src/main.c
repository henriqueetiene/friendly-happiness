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

void testeBubleSort()
{
    int *vetor = geraVetor(10);

    printf("Algoritmo de ordenação Buble Sort\n");
    printf("Vetor desordenado\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }

    bubleSort(vetor, 10);

    printf("\nVetor ordenado\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
}

void testeInsertionSort()
{
    int *vetor = geraVetor(10);

    printf("Algoritmo de ordenação Insertion Sort\n");
    printf("Vetor desordenado\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }

    insertionSort(vetor, 10);

    printf("\nVetor ordenado\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);
}

void testeSelectionSort()
{
    int *vetor = geraVetor(10);

    printf("Algoritmo de ordenação Selection Sort\n");
    printf("Vetor desordenado\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }

    selectionSort(vetor, 10);

    printf("\nVetor ordenado\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);
}

int main(int argc, char const *argv[])
{
    testeBubleSort();
    printf("\n\n");
    testeInsertionSort();
    printf("\n\n");
    testeSelectionSort();

    return 0;
}
