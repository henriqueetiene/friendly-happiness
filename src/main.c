#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int *geraVetor(int tamanho)
{
    int *vetor = malloc(tamanho * sizeof(int));

    srand(time(NULL));

    if (vetor == NULL)
    {
        printf("Erro na alocação de memoria.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 10; i++) {
        vetor[i] = rand() % tamanho;
    }

    return vetor;
}

void testeBubleSort(int *vetor, int tamanho)
{
    printf("Algoritmo de ordenação Buble Sort\n");

    printf("Ordenando vetor de %d posições\n", tamanho);
    bubleSort(vetor, tamanho);

    free(vetor);
}

void testeInsertionSort(int *vetor, int tamanho)
{
    printf("Algoritmo de ordenação Insertion Sort\n");
    
    printf("Ordenando vetor de %d posições\n", tamanho);
    insertionSort(vetor, tamanho);

    free(vetor);
}

void testeSelectionSort(int *vetor, int tamanho)
{
    printf("Algoritmo de ordenação Selection Sort\n");

    printf("Ordenando vetor de %d posições\n", tamanho);
    selectionSort(vetor, tamanho);

    free(vetor);
}

void copiaVetor(int *vetorOriginal, int *novoVetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        novoVetor[i] = vetorOriginal[i];
    }
    
}

int main(int argc, char const *argv[])
{
    int tamanho = 100000;

    printf("Gerando vetor de %d posições\n\n", tamanho);
    int *vetor = geraVetor(tamanho);

    printf("Copiando vetor para ordenação Buble Sort\n");
    int *vetorBubble = malloc(tamanho * sizeof(int));
    copiaVetor(vetor, vetorBubble, tamanho);
    testeBubleSort(vetorBubble, tamanho);

    printf("\n\n");

    printf("Copiando vetor para ordenação Insertion Sort\n");
    int *vetorInsertion = malloc(tamanho * sizeof(int));
    copiaVetor(vetor, vetorInsertion, tamanho);
    testeInsertionSort(vetorInsertion, tamanho);

    printf("\n\n");

    printf("Copiando vetor para ordenação Selection Sort\n");
    int *vetorSelection = malloc(tamanho * sizeof(int));
    copiaVetor(vetor, vetorSelection, tamanho);
    testeSelectionSort(vetorSelection, tamanho);

    return 0;
}
