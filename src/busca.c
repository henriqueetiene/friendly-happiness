#include "busca.h"

int buscaBinaria(int *v, int n, int elem)
{
    int inicio, meio, final;
    
    inicio = 0;
    final = n - 1;

    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        if (elem < v[meio])
        {
            final = meio - 1;
        }
        else
        {
            if (elem > v[meio])
            {
                inicio = meio + 1;
            }
            else
            {
                return meio;
            }
        }
    }

    return -1;
}

int buscaLinear(int *v, int n, int elem)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (elem == v[i])
        {
            return i;
        }
    }

    return -1;
}

int buscaOrdenada(int *v, int n, int elem)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (elem == v[i])
        {
            return i;
        }
        else
        {
            if (elem < v[i])
            {
                return -1;
            }
        }
    }

    return -1;
}