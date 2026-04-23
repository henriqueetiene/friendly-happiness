#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ordenacao.h"
#include "busca.h"

int *geraVetor(long tamanho)
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

int *copiaVetor(int *vetorOriginal, long tamanho)
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

void testeBubleSort(int *vetor, long tamanho)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    printf("Ordenando vetor de %ld posições\n", tamanho);
    timespec_get(&inicio, TIME_UTC);
    bubleSort(vetor, tamanho, &passos);
    timespec_get(&fim, TIME_UTC);

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);

    printf("Numero de passos: %lld\n", passos);

    free(vetor);
}

void testeInsertionSort(int *vetor, long tamanho)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;
    
    printf("Ordenando vetor de %ld posições\n", tamanho);
    timespec_get(&inicio, TIME_UTC);
    insertionSort(vetor, tamanho, &passos);
    timespec_get(&fim, TIME_UTC);

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);

    printf("Numero de passos: %lld\n", passos);

    free(vetor);
}

void testeSelectionSort(int *vetor, long tamanho)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    printf("Ordenando vetor de %ld posições\n", tamanho);
    timespec_get(&inicio, TIME_UTC);
    selectionSort(vetor, tamanho, &passos);
    timespec_get(&fim, TIME_UTC);

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);

    printf("Numero de passos: %lld\n", passos);

    free(vetor);
}

void testeQuickSort(int *vetor, long tamanho)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    printf("Ordenando vetor de %ld posições\n", tamanho);
    timespec_get(&inicio, TIME_UTC);
    quickSort(vetor, 0, tamanho - 1, &passos);
    timespec_get(&fim, TIME_UTC);

    tempo_segundos = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo de execução: %.10f segundos\n", tempo_segundos);

    printf("Numero de passos: %lld\n", passos);

    free(vetor);
}

void testeBuscaBinaria(int *vetor, long tamanho, int elem)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    timespec_get(&inicio, TIME_UTC);
    int posicao = buscaBinaria(vetor, tamanho, elem, &passos);
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

    printf("Numero de passos: %lld\n", passos);
}

void testeBuscaLinear(int *vetor, long tamanho, int elem)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    timespec_get(&inicio, TIME_UTC);
    int posicao = buscaLinear(vetor, tamanho, elem, &passos);
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

    printf("Numero de passos: %lld\n", passos);
}

void testeBuscaOrdenada(int *vetor, long tamanho, int elem)
{
    struct timespec inicio, fim;
    double tempo_segundos;
    long long passos = 0;

    timespec_get(&inicio, TIME_UTC);
    int posicao = buscaOrdenada(vetor, tamanho, elem, &passos);
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

    printf("Numero de passos: %lld\n", passos);
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Erro: Quantidade de argumentos invalido\n");
        return 1;
    }

    char *str = (char *)argv[2];
    char *end;
    long tamanho = strtol(str, &end, 10);

    if (str == end) {
        printf("Erro: informe um numero válido para o tamanho do vetor\n");
    }

    int *vetor = geraVetor(tamanho);

    if (strcmp(argv[1], "buble") == 0)
    {
        printf("----------Buble Sort----------\n");
        int *vetorBubble = copiaVetor(vetor, tamanho);
        testeBubleSort(vetorBubble, tamanho);

        free(vetorBubble);

        printf("\n\n");
    }
    else if (strcmp(argv[1], "insertion") == 0)
    {
        printf("----------Insertion Sort----------\n");
        int *vetorInsertion = copiaVetor(vetor, tamanho);
        testeInsertionSort(vetorInsertion, tamanho);

        free(vetorInsertion);

        printf("\n\n");
    }
    else if (strcmp(argv[1], "selection") == 0)
    {
        printf("----------Selection Sort----------\n");
        int *vetorSelection = copiaVetor(vetor, tamanho);
        testeSelectionSort(vetorSelection, tamanho);

        free(vetorSelection);

        printf("\n\n");
    }
    else if (strcmp(argv[1], "quick") == 0)
    {
        printf("----------Quick Sort----------\n");
        int *vetorQuick = copiaVetor(vetor, tamanho);
        testeQuickSort(vetorQuick, tamanho);

        free(vetorQuick);

        printf("\n\n");
    }
    else if (strcmp(argv[1], "buscabinaria") == 0)
    {
        printf("----------Busca Binaria----------\n");
        int *vetorBuscaBinaria = copiaVetor(vetor, tamanho);

        long long passosQuickBinaria = 0;

        printf("Ordenando vetor de %ld posições para busca\n\n", tamanho);
        quickSort(vetorBuscaBinaria, 0, tamanho - 1, &passosQuickBinaria);

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
    }
    else if (strcmp(argv[1], "buscalinear") == 0)
    {
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
    }
    else if (strcmp(argv[1], "buscaordenada") == 0)
    {
        printf("----------Busca Ordenada----------\n");
        int *vetorBuscaOrdenada = copiaVetor(vetor, tamanho);

        long long passosQuickOrdenada = 0;

        printf("Ordenando vetor de %ld posições para busca\n\n", tamanho);
        quickSort(vetorBuscaOrdenada, 0, tamanho - 1, &passosQuickOrdenada);

        printf("Buscando elemento na posição v[0]\n");
        testeBuscaOrdenada(vetorBuscaOrdenada, tamanho, vetorBuscaOrdenada[0]);
        printf("\nBuscando elemento na posição v[n - 1]\n");
        testeBuscaOrdenada(vetorBuscaOrdenada, tamanho, vetorBuscaOrdenada[tamanho - 1]);
        printf("\nBuscando elemento na posição v[n / 2]\n");
        testeBuscaOrdenada(vetorBuscaOrdenada, tamanho, vetorBuscaOrdenada[tamanho / 2]);
        printf("\nBuscando elemento na posição v[n / 3]\n");
        testeBuscaOrdenada(vetorBuscaOrdenada, tamanho, vetorBuscaOrdenada[tamanho / 3]);

        free(vetorBuscaOrdenada);
    }
    else
    {
        printf("Erro: nenhum algoritmo encontrado\n");
        free(vetor);
        return 1;
    }

    free(vetor);

    return 0;
}
