#include <stdio.h>
#include "ordenacao.h"

void bubleSort(int *v, int n)
{
    int continua, aux, fim = n;
    do
    {
        continua = 0;
        for (int i = 0; i < fim - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i + 1;
            }
        }
    } while (continua != 0);
}

void insertionSort(int *v, int n)
{
    int aux, j;
    for (int i = 1; i < n; i++)
    {
        aux = v[i];
        for (j = i; (j > 0) && (aux < v[j - 1]); j--)
        {
            v[j] = v[j - 1];
        }
        v[j] = aux;
    }
}

void selectionSort(int *v, int n)
{
    int minIndex, aux;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            aux = v[minIndex];
            v[minIndex] = v[i];
            v[i] = aux;
        }
    }
}