#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <time.h>
#include "funcoes.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int resp1, resp2;
    uint64_t movimentos = 0, comparacoes = 0;
    do
    {
        menu1();
        cout << "Escolha a opção do menu: \n";
        cin >> resp1;
    } while (resp1 == 0 && resp1 > 7);
    do
    {
        system("cls");
        menu2();
        cout << "Escolha a opção do menu: \n";
        cin >> resp2;
    } while (resp2 == 0 && resp2 > 23);

    string nome;
    int tamanho;
    switch (resp2)
    {
    case 1:
        nome = "../DicionarioAleatorio-29855.txt";
        tamanho = 29855;
        break;
    case 2:
        nome = "../DicionarioAleatorio-261791.txt";
        tamanho = 261791;
        break;
    case 3:
        nome = "../DicionarioInversamenteOrdenado-29855.txt";
        tamanho = 29855;
        break;
    case 4:
        nome = "../DicionarioInversamenteOrdenado-261791.txt";
        tamanho = 261791;
        break;
    case 5:
        nome = "../DicionarioOrdenado-29855.txt";
        tamanho = 29855;
        break;
    case 6:
        nome = "../DicionarioOrdenado-261791.txt";
        tamanho = 261791;
        break;
    case 7:
        nome = "../ListaAleatoria-1000.txt";
        tamanho = 1000;
        break;
    case 8:
        nome = "../ListaAleatoria-10000.txt";
        tamanho = 10000;
        break;
    case 9:
        nome = "../ListaAleatoria-100000.txt";
        tamanho = 100000;
        break;
    case 10:
        nome = "../ListaAleatoria-1000000.txt";
        tamanho = 1000000;
        break;
    case 11:
        nome = "../ListaInversamenteOrdenada-1000.txt";
        tamanho = 1000;
        break;
    case 12:
        nome = "../ListaInversamenteOrdenada-10000.txt";
        tamanho = 10000;
        break;
    case 13:
        nome = "../ListaInversamenteOrdenada-100000.txt";
        tamanho = 100000;
        break;
    case 14:
        nome = "../ListaInversamenteOrdenada-1000000.txt";
        tamanho = 1000000;
        break;
    case 15:
        nome = "../ListaOrdenada-1000.txt";
        tamanho = 1000;
        break;
    case 16:
        nome = "../ListaOrdenada-10000.txt";
        tamanho = 10000;
        break;
    case 17:
        nome = "../ListaOrdenada-100000.txt";
        tamanho = 100000;
        break;
    case 18:
        nome = "../ListaOrdenada-1000000.txt";
        tamanho = 1000000;
        break;
    case 19:
        nome = "../ListaQuaseOrdenada-1000.txt";
        tamanho = 1000;
        break;
    case 20:
        nome = "../ListaQuaseOrdenada-10000.txt";
        tamanho = 10000;
        break;
    case 21:
        nome = "../ListaQuaseOrdenada-100000.txt";
        tamanho = 100000;
        break;
    case 22:
        nome = "../ListaQuaseOrdenada-1000000.txt";
        tamanho = 1000000;
        break;
    }

    int *vetor = new int[tamanho];
    AbrirArquivoInt(vetor, nome, tamanho);
    string *vetorString = new string[tamanho];
    AbrirArquivoString(vetorString, nome, tamanho);
    clock_t TempoInicial;
    clock_t TempoFinal;
    ofstream salvar;
    salvar.open("../Resultado.txt",fstream::app);
    if (resp2 >= 1 && resp2 < 7)
    {
        switch (resp1)
        {
        case 1:
            TempoInicial = clock();
            BubbleSortString(vetorString, tamanho, comparacoes, movimentos);
            TempoFinal = clock();
            ImprimeString(vetorString, tamanho);
            if (salvar.is_open())
            {
                salvar << "BubbleSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 2:
            TempoInicial = clock();
            InsertionSort(vetorString, tamanho, comparacoes, movimentos);
            TempoFinal = clock();
            ImprimeString(vetorString, tamanho);
            if (salvar.is_open())
            {
                salvar << "InsertionSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 3:
            TempoInicial = clock();
            SelectionSort(vetorString, tamanho, comparacoes, movimentos);
            TempoFinal = clock();
            ImprimeString(vetorString, tamanho);
            if (salvar.is_open())
            {
                salvar << "SelectionSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 4:
            TempoInicial = clock();
            ShellSort(vetorString, tamanho, comparacoes, movimentos);
            TempoFinal = clock();
            ImprimeString(vetorString, tamanho);
            if (salvar.is_open())
            {
                salvar << "ShellSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 5:
            TempoInicial = clock();
            QuickSort(vetorString, 0, tamanho - 1, comparacoes, movimentos);
            TempoFinal = clock();
            ImprimeString(vetorString, tamanho);
            if (salvar.is_open())
            {
                salvar << "QuickSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 6:
            TempoInicial = clock();
            MergeSortString(vetorString, 0, tamanho - 1, comparacoes, movimentos);
            TempoFinal = clock();
            ImprimeString(vetorString, tamanho);
            if (salvar.is_open())
            {
                salvar << "MergeSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        }
    }
    else
    {

        switch (resp1)
        {
        case 1:
            TempoInicial = clock();
            BubbleSort(vetor, tamanho, comparacoes, movimentos);
            TempoFinal = clock();
            Imprime(vetor, tamanho);
            if (salvar.is_open())
            {
                salvar << "BubbleSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 2:
            TempoInicial = clock();
            InsertionSort(vetor, tamanho, comparacoes, movimentos);
            TempoFinal = clock();
            Imprime(vetor, tamanho);
            if (salvar.is_open())
            {
                salvar << "InsertionSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 3:
            TempoInicial = clock();
            SelectionSort(vetor, tamanho, comparacoes, movimentos);
            TempoFinal = clock();
            Imprime(vetor, tamanho);
            if (salvar.is_open())
            {
                salvar << "SelectionSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 4:
            TempoInicial = clock();
            ShellSort(vetor, tamanho, comparacoes, movimentos);
            TempoFinal = clock();
            Imprime(vetor, tamanho);
            if (salvar.is_open())
            {
                salvar << "ShellSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 5:
            TempoInicial = clock();
            QuickSort(vetor, 0, tamanho - 1, comparacoes, movimentos);
            TempoFinal = clock();
            Imprime(vetor, tamanho);
            if (salvar.is_open())
            {
                salvar << "QuickSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        case 6:
            TempoInicial = clock();
            MergeSort(vetor, 0, tamanho - 1, comparacoes, movimentos);
            TempoFinal = clock();
            Imprime(vetor, tamanho);
            if (salvar.is_open())
            {
                salvar << "MergeSort " << nome << endl;
            }
            else
            {
                cerr << "Nao foi possivel criar o arquivo";
            }
            break;
        }
    }
    clock_t clockTicksTaken = TempoFinal - TempoInicial;
    double TempoEmSegundos = clockTicksTaken / (double)CLOCKS_PER_SEC;
    cout << "\n\nTempo para ordernar o vetor: " << TempoEmSegundos << "\n";
    cout << "Comparações feitas: " << comparacoes << "\n";
    cout << "Movimentos feitos: " << movimentos << "\n";
    if (salvar.is_open())
    {
        salvar << "\n\nTempo para ordernar o vetor: " << TempoEmSegundos << "\n";
        salvar << "Comparações feitas: " << comparacoes << "\n";
        salvar << "Movimentos feitos: " << movimentos << "\n\n";
    }
    else
    {
        cerr << "Nao foi possivel criar o arquivo";
    }
    system("pause");
    salvar.close();
    delete vetor;
    delete vetorString;

    cout << endl;
    return 0;
}
