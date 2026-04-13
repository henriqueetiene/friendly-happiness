#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "busca.h"

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

void testeBuscaBinaria(int *vetor, int tamanho, int elem)
{
    struct timespec inicio, fim;
    double tempo_segundos;

    timespec_get(&inicio, TIME_UTC);
    int posicao = buscaBinaria(vetor, tamanho, elem);
    timespec_get(&fim, TIME_UTC);

    if (posicao != -1)
    {
        printf("Elemento Encontrado\n");
    }
    else
    {
        printf("Elemento não Encontrado\n");
    }

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);
}

void testeBuscaLinear(int *vetor, int tamanho, int elem)
{
    struct timespec inicio, fim;
    double tempo_segundos;

    timespec_get(&inicio, TIME_UTC);
    int posicao = buscaLinear(vetor, tamanho, elem);
    timespec_get(&fim, TIME_UTC);

    if (posicao != -1)
    {
        printf("Elemento Encontrado\n");
    }
    else
    {
        printf("Elemento não Encontrado\n");
    }

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);
}

void testeBuscaOrdenada(int *vetor, int tamanho, int elem)
{
    struct timespec inicio, fim;
    double tempo_segundos;

    timespec_get(&inicio, TIME_UTC);
    int posicao = buscaOrdenada(vetor, tamanho, elem);
    timespec_get(&fim, TIME_UTC);

    if (posicao != -1)
    {
        printf("Elemento Encontrado\n");
    }
    else
    {
        printf("Elemento não Encontrado\n");
    }

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);
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

    printf("\n\n");

    printf("----------Busca Binaria----------\n");
    int *vetorBuscaBinaria = copiaVetor(vetor, tamanho);

    long long passos = 0;

    printf("Ordenando vetor de %d posições para busca\n\n", tamanho);
    quickSort(vetorBuscaBinaria, 0, tamanho - 1, &passos);

    printf("Buscando elemento na posição v[0]\n");
    testeBuscaBinaria(vetorBuscaBinaria, tamanho, vetorBuscaBinaria[0]);
    printf("\nBuscando elemento na posição v[n - 1]\n");
    testeBuscaBinaria(vetorBuscaBinaria, tamanho, vetorBuscaBinaria[tamanho - 1]);
    printf("\nBuscando elemento na posição v[n / 2]\n");
    testeBuscaBinaria(vetorBuscaBinaria, tamanho, vetorBuscaBinaria[tamanho / 2]);
    printf("\nBuscando elemento na posição v[n / 3]\n");
    testeBuscaBinaria(vetorBuscaBinaria, tamanho, vetorBuscaBinaria[tamanho / 3]);

    free(vetorBuscaBinaria);

    printf("\n\n");

    printf("----------Busca Linear----------\n");
    int *vetorBuscaLinear = copiaVetor(vetor, tamanho);

    printf("Buscando elemento na posição v[0]\n");
    testeBuscaLinear(vetorBuscaLinear, tamanho, vetorBuscaLinear[0]);
    printf("\nBuscando elemento na posição v[n - 1]\n");
    testeBuscaLinear(vetorBuscaLinear, tamanho, vetorBuscaLinear[tamanho - 1]);
    printf("\nBuscando elemento na posição v[n / 2]\n");
    testeBuscaLinear(vetorBuscaLinear, tamanho, vetorBuscaLinear[tamanho / 2]);
    printf("\nBuscando elemento na posição v[n / 3]\n");
    testeBuscaLinear(vetorBuscaLinear, tamanho, vetorBuscaLinear[tamanho / 3]);

    free(vetorBuscaLinear);

    printf("\n\n");

    printf("----------Busca Ordenada----------\n");
    int *vetorBuscaOrdenada = copiaVetor(vetor, tamanho);

    passos = 0;

    printf("Ordenando vetor de %d posições para busca\n\n", tamanho);
    quickSort(vetorBuscaOrdenada, 0, tamanho - 1, &passos);

    printf("Buscando elemento na posição v[0]\n");
    testeBuscaOrdenada(vetorBuscaOrdenada, tamanho, vetorBuscaOrdenada[0]);
    printf("\nBuscando elemento na posição v[n - 1]\n");
    testeBuscaOrdenada(vetorBuscaOrdenada, tamanho, vetorBuscaOrdenada[tamanho - 1]);
    printf("\nBuscando elemento na posição v[n / 2]\n");
    testeBuscaOrdenada(vetorBuscaOrdenada, tamanho, vetorBuscaOrdenada[tamanho / 2]);
    printf("\nBuscando elemento na posição v[n / 3]\n");
    testeBuscaOrdenada(vetorBuscaOrdenada, tamanho, vetorBuscaOrdenada[tamanho / 3]);

    free(vetorBuscaOrdenada);

    free(vetor);

    return 0;
}
