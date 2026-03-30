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

void testeBubleSort(int n)
{
    int *vetor = geraVetor(n);

    printf("Algoritmo de ordenação Buble Sort\n");
    printf("Vetor desordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    bubleSort(vetor, n);

    printf("\nVetor ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
}

void testeInsertionSort(int n)
{
    int *vetor = geraVetor(n);

    printf("Algoritmo de ordenação Insertion Sort\n");
    printf("Vetor desordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    insertionSort(vetor, n);

    printf("\nVetor ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);
}

void testeSelectionSort(int n)
{
    int *vetor = geraVetor(n);

    printf("Algoritmo de ordenação Selection Sort\n");
    printf("Vetor desordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    selectionSort(vetor, n);

    printf("\nVetor ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);
}

int main(int argc, char const *argv[])
{
    testeBubleSort(10);
    printf("\n\n");
    testeInsertionSort(10);
    printf("\n\n");
    testeSelectionSort(10);

    return 0;
}
