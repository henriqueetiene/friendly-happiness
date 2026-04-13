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

    for(int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % tamanho;
    }

    return vetor;
}

int *copiaVetor(int *vetorOriginal, int tamanho)
{
    int *novoVetor = malloc(tamanho * sizeof(int));

    if (novoVetor == NULL)
    {
        printf("Erro na alocação de memoria para o vetor de copia.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanho; i++)
    {
        novoVetor[i] = vetorOriginal[i];
    }

    return novoVetor;
}

void testeBubleSort(int *vetor, int tamanho)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    printf("Ordenando vetor de %d posições\n", tamanho);
    timespec_get(&inicio, TIME_UTC);
    bubleSort(vetor, tamanho, &passos);
    timespec_get(&fim, TIME_UTC);

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);

    printf("Numero de passos: %lld\n", passos);

    free(vetor);
}

void testeInsertionSort(int *vetor, int tamanho)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;
    
    printf("Ordenando vetor de %d posições\n", tamanho);
    timespec_get(&inicio, TIME_UTC);
    insertionSort(vetor, tamanho, &passos);
    timespec_get(&fim, TIME_UTC);

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);

    printf("Numero de passos: %lld\n", passos);

    free(vetor);
}

void testeSelectionSort(int *vetor, int tamanho)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    printf("Ordenando vetor de %d posições\n", tamanho);
    timespec_get(&inicio, TIME_UTC);
    selectionSort(vetor, tamanho, &passos);
    timespec_get(&fim, TIME_UTC);

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);

    printf("Numero de passos: %lld\n", passos);

    free(vetor);
}

void testeQuickSort(int *vetor, int tamanho)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    printf("Ordenando vetor de %d posições\n", tamanho);
    timespec_get(&inicio, TIME_UTC);
    quickSort(vetor, 0, tamanho - 1, &passos);
    timespec_get(&fim, TIME_UTC);

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);

    printf("Numero de passos: %lld\n", passos);

    free(vetor);
}

int main(int argc, char const *argv[])
{
    int tamanho = 100000;

    int *vetor = geraVetor(tamanho);

    printf("----------Buble Sort----------\n");
    int *vetorBubble = copiaVetor(vetor, tamanho);
    testeBubleSort(vetorBubble, tamanho);

    printf("\n\n");

    printf("----------Insertion Sort----------\n");
    int *vetorInsertion = copiaVetor(vetor, tamanho);
    testeInsertionSort(vetorInsertion, tamanho);

    printf("\n\n");

    printf("----------Selection Sort----------\n");
    int *vetorSelection = copiaVetor(vetor, tamanho);
    testeSelectionSort(vetorSelection, tamanho);

    printf("\n\n");

    printf("----------Quick Sort----------\n");
    int *vetorQuick = copiaVetor(vetor, tamanho);
    testeQuickSort(vetorQuick, tamanho);

    free(vetor);

    return 0;
}
