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

    // Criando um array para armazenar a contagem de cada elemento
    int* countArray = new int[maxVal - minVal + 1]{0};

    // Contando a ocorrência de cada elemento na lista
    currentNode = head;
    while (currentNode != nullptr) {
        countArray[currentNode->iPayload - minVal]++;
        currentNode = currentNode->ptrNext;
    }

    // Reconstruindo a lista com os elementos ordenados
    currentNode = head;
    int index = 0;
    for (int i = minVal; i <= maxVal; i++) {
        while (countArray[i - minVal] > 0) {
            currentNode->iPayload = i;
            countArray[i - minVal]--;
            currentNode = currentNode->ptrNext;
        }
    }

    delete[] countArray;
}
