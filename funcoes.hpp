#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>

using namespace std;

void menu1();
void menu2();
void BubbleSort(auto v[], int n, uint64_t &movimentos, uint64_t &comparacoes);
void BubbleSortString(auto v[], int n, uint64_t &movimentos, uint64_t &comparacoes);
void InsertionSort(auto vetor[], int tamanho, uint64_t &comparacoes, uint64_t &movimentos);
void SelectionSort(auto vetor[], int tamanho, uint64_t &comparacoes, uint64_t &movimentos);
void ShellSort(auto vetor[], int tamanho, uint64_t &comparacoes, uint64_t &movimentos);
void QuickSort(auto vetor[], int left, int right, uint64_t &comparacoes, uint64_t &movimentos);
void Merge(auto vetor[], int p, int q, int r, uint64_t &comparacoes, uint64_t &movimentos);
void MergeSort(auto vetor[], int l, int r, uint64_t &comparacoes, uint64_t &movimentos);
void MergeString(auto vetor[], int p, int q, int r, uint64_t &comparacoes, uint64_t &movimentos);
void MergeSortString(auto vetor[], int l, int r, uint64_t &comparacoes, uint64_t &movimentos);
void Imprime(int *vetor, uint64_t n);
void ImprimeString(string *vetor, uint64_t n);
void AbrirArquivoInt(int *vetor, string nome, uint64_t tamanho);
void AbrirArquivoString(string *vetor, string nome, uint64_t tamanho);

#endif
