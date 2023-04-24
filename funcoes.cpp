#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <time.h>
#include "funcoes.hpp"
using namespace std;

void menu1()
{
    system("cls");
    cout << "\n1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Shell Sort\n";
    cout << "5. Quick Sort\n";
    cout << "6. Merge Sort\n";
    cout << "0. Exit\n\n";
}

void menu2()
{
    system("cls");
    cout << "\n1. Dionário Aleatório (29855)\n";
    cout << "2. Dionário Aleatório (261791)\n";
    cout << "3. Dicionário Inversamente Ordenado (29855)\n";
    cout << "4. Dicionário Inversamente Ordenado (261791)\n";
    cout << "5. Dicionário Ordenado (26855)\n";
    cout << "6. Dicionário Ordenado (261791)\n";
    cout << "7. Números Aleatórios(1000)\n";
    cout << "8. Números Aleatórios(10000)\n";
    cout << "9. Números Aleatórios(100000)\n";
    cout << "10. Números Aleatórios(1000000)\n";
    cout << "11. Números Inversamente Ordenados (1000)\n";
    cout << "12. Números Inversamente Ordenados (10000)\n";
    cout << "13. Números Inversamente Ordenados (100000)\n";
    cout << "14. Números Inversamente Ordenados (1000000)\n";
    cout << "15. Números Ordenados (1000)\n";
    cout << "16. Números Ordenados (10000)\n";
    cout << "17. Números Ordenados (100000)\n";
    cout << "18. Números Ordenados (1000000)\n";
    cout << "19. Números Quase Ordenados (1000)\n";
    cout << "20. Números Quase Ordenados (10000)\n";
    cout << "21. Números Quase Ordenados (100000)\n";
    cout << "22. Números Quase Ordenados (1000000)\n";
    cout << "0. Exit.\n\n";
}

void BubbleSort(auto v[], int n, uint64_t &comparacoes, uint64_t &movimentos)
{
    uint64_t i, j, swap;
    int aux;
    for (i = n - 1; i > 0; i--)
    {
        swap = 0;
        for (j = 0; j < i; j++)
        {
            comparacoes = comparacoes + 1;
            if (v[j] > v[j + 1])
            {
                movimentos = movimentos + 1;
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                swap = 1;
            }
        }
        if (swap == 0)
        {
            break;
        }
    }
}

void BubbleSortString(auto v[], int n, uint64_t &comparacoes, uint64_t &movimentos)
{
    uint64_t i, j, swap;
    string aux;
    for (i = n - 1; i > 0; i--)
    {
        swap = 0;
        for (j = 0; j < i; j++)
        {
            comparacoes = comparacoes + 1;
            if (v[j] > v[j + 1])
            {
                movimentos = movimentos + 1;
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                swap = 1;
            }
        }
        if (swap == 0)
        {
            break;
        }
    }
}

void InsertionSort(auto vetor[], int tamanho, uint64_t &comparacoes, uint64_t &movimentos)
{
    int j;
    auto aux = vetor[0];

    for (int i = 1; i < tamanho; i++)
    {
        aux = vetor[i];
        j = i - 1;

        comparacoes += 1;
        while (j >= 0 && vetor[j] > aux)
        {
            comparacoes += 1;
            movimentos += 1;

            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}

void SelectionSort(auto vetor[], int tamanho, uint64_t &comparacoes, uint64_t &movimentos)
{
    int min;
    auto aux = vetor[0];

    for (int i = 0; i < tamanho - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            comparacoes += 1;

            if (vetor[j] < vetor[min])
            {
                min = j;
                movimentos += 1;
            }
        }   

        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}

void ShellSort(auto vetor[], int tamanho, uint64_t &comparacoes, uint64_t &movimentos)
{
    int i, j, h;
    auto aux = vetor[0];

    for (h = 1; h < tamanho; h = 3 * h + 1)
        ;

    while (h > 1)
    {
        h = h / 3;

        for (i = h; i < tamanho; i++)
        {
            aux = vetor[i];
            j = i;

            while (j >= h && vetor[j - h] > aux)
            {
                comparacoes += 2;
                movimentos += 1;

                vetor[j] = vetor[j - h];
                j = j - h;
            }
            vetor[j] = aux;
        }
    }
}

void QuickSort(auto vetor[], int left, int right, uint64_t &comparacoes, uint64_t &movimentos)
{
    auto aux = vetor[0];
    int i = left, j = right;
    auto pivot = vetor[(left + right) / 2];

    while (i <= j)
    {
        comparacoes += 1;
        while (vetor[i] < pivot)
        {
            comparacoes += 1;
            i++;
        }
        comparacoes += 1;
        while (vetor[j] > pivot)
        {
            comparacoes += 1;
            j--;
        }
        comparacoes += 1;
        if (i <= j)
        {
            movimentos += 1;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        QuickSort(vetor, left, j, comparacoes, movimentos);
    }
    if (i < right)
    {
        QuickSort(vetor, i, right, comparacoes, movimentos);
    }
}

void Merge(auto vetor[], int p, int q, int r, uint64_t &comparacoes, uint64_t &movimentos)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1];
    int *M = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = vetor[p + i];
        movimentos += 1;
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = vetor[q + 1 + j];
        movimentos += 1;
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        comparacoes += 1;
        if (L[i] <= M[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        movimentos += 1;
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        movimentos += 1;
        vetor[k] = M[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] M;
}

void MergeSort(auto vetor[], int l, int r, uint64_t &comparacoes, uint64_t &movimentos)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(vetor, l, m, comparacoes, movimentos);
        MergeSort(vetor, m + 1, r, comparacoes, movimentos);

        Merge(vetor, l, m, r, comparacoes, movimentos);
    }
}

void MergeString(auto vetor[], int p, int q, int r, uint64_t &comparacoes, uint64_t &movimentos)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    string *L = new string[n1];
    string *M = new string[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = vetor[p + i];
        movimentos += 1;
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = vetor[q + 1 + j];
        movimentos += 1;
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        comparacoes += 1;
        if (L[i] <= M[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        movimentos += 1;
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        movimentos += 1;
        vetor[k] = M[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] M;
}

void MergeSortString(auto vetor[], int l, int r, uint64_t &comparacoes, uint64_t &movimentos)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSortString(vetor, l, m, comparacoes, movimentos);
        MergeSortString(vetor, m + 1, r, comparacoes, movimentos);

        MergeString(vetor, l, m, r, comparacoes, movimentos);
    }
}

void Imprime(int *vetor, uint64_t n)
{
    for (uint64_t i = 0; i < n; i++)
    {
        cout << vetor[i] << " ";
    }
}

void ImprimeString(string *vetor, uint64_t n)
{
    for (uint64_t i = 0; i < n; i++)
    {
        cout << vetor[i] << " ";
    }
}

void AbrirArquivoInt(int *vetor, string nome, uint64_t tamanho)
{
    ifstream fout;
    fout.open(nome);
    if (!fout.fail())
    {

        for (uint64_t i = 0; i < tamanho; i++)
        {
            fout >> vetor[i];
        }
    }
    else
    {
        cerr << "File was unable to open!";
    }
    fout.close();
}

void AbrirArquivoString(string *vetor, string nome, uint64_t tamanho)
{
    ifstream fout;
    fout.open(nome);
    if (!fout.fail())
    {

        for (uint64_t i = 0; i < tamanho; i++)
        {
            fout >> vetor[i];
        }
    }
    else
    {
        cerr << "File was unable to open!";
    }
    fout.close();
}
