#include "ordenacao.h"

void bubleSort(int *v, long n, long long *passos)
{
    int i, continua, aux, fim = n;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            (*passos)++;
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}

void insertionSort(int *v, long n, long long *passos)
{
    int i, j, atual;
    for (i = 1; i < n; i++)
    {
        atual = v[i];
        for (j = i; (j > 0) && (atual < v[j - 1]); j--)
        {
            (*passos)++;
            v[j] = v[j - 1];
        }
        v[j] = atual;
    }
}

void selectionSort(int *v, long n, long long *passos)
{
    int i, j, menor, troca;
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            (*passos)++;
            if (v[j] < v[menor])
            {
                menor = j;
            }
        }
        if (i != menor)
        {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

int particiona(int *v, int inicio, long final, long long *passos)
{
    int esq, dir, pivo, aux;
    
    esq = inicio;
    dir = final;
    pivo = v[inicio];

    while (esq < dir)
    {
        while (esq <= final && v[esq] <= pivo)
        {
            esq++;
            (*passos)++;
        }
        while (dir >= 0 && v[dir] > pivo)
        {
            dir--;
            (*passos)++;
        }
        if (esq < dir)
        {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;

    return dir;
}

void quickSort(int *v, int inicio, long fim, long long *passos)
{
    if (fim > inicio)
    {
        int pivo = particiona(v, inicio, fim, passos);
        quickSort(v, inicio, pivo - 1, passos);
        quickSort(v, pivo + 1, fim, passos);
    }
}