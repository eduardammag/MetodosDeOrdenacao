#include "../sorting_methods.h"
#include "../functions_list/functions_list.h"
#include <iostream>
#include <cstdlib> // para o uso do malloc
#include <climits> // para usar INT_MAX e INT_MIN

using namespace std;

// Função para ordenar os valores de uma lista duplamente encadeada em ordem crescente usando o método Counting Sort
void countingSort(Node* head) {
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int length = 0;
    Node* currentNode = head;

    // Encontrando o maior e o menor valor na lista e calculando o comprimento da lista
    while (currentNode != nullptr) {
        length++;
        if (currentNode->iPayload < minVal)
            minVal = currentNode->iPayload;
        if (currentNode->iPayload > maxVal)
            maxVal = currentNode->iPayload;
        currentNode = currentNode->ptrNext;
    }

    // Determina o tamanho do array auxiliar para o counting sort
    int range = maxVal - minVal + 1;
    int* count = new int[range]{0}; // Inicializa todos os elementos do array com 0

    // Conta a ocorrência de cada elemento na lista
    currentNode = head;
    while (currentNode != nullptr) {
        ++count[currentNode->iPayload - minVal];
        currentNode = currentNode->ptrNext;
    }

    // Atualiza a lista com os elementos ordenados usando o array count
    currentNode = head;
    int index = 0;
    while (currentNode != nullptr) {
        while (count[index] == 0)
            ++index;
        currentNode->iPayload = index + minVal;
        --count[index];
        currentNode = currentNode->ptrNext;
    }

    delete[] count;
}
