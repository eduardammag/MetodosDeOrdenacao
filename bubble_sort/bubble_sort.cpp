#include "../sorting_methods.h"
#include "../functions_list/functions_list.h"
#include <iostream>
#include <cstdlib> //por vezes é necessário para o uso do malloc

using namespace std;

// Função para ordenar os valores de uma lista duplamente encadeada em ordem crescente usando o método Bubble Sort
void bubbleSort(Node* head, int length)
{
    Node* currentNode;
    Node* nextNode = nullptr;

    for (int i = 0; i < length - 1; ++i)
    {
        currentNode = head;

        while (currentNode->ptrNext != nextNode)
        {
            if (currentNode->iPayload > currentNode->ptrNext->iPayload)
                swapValue(currentNode->iPayload, currentNode->ptrNext->iPayload);
                
            currentNode = currentNode->ptrNext;
        }

        nextNode = currentNode;
    }
}

// Função para ordenar uma lista duplamente encadeada usando o método Bubble Sort de forma otimizada
void optimizedBubbleSort(Node* head, int length)
{
    bool bUnordered = 0;
    Node* currentNode;
    Node* nextNode = nullptr;

    for (int i = 0; i < length - 1; ++i)
    {
        bUnordered = 0;
        currentNode = head;

        while (currentNode->ptrNext != nextNode)
        {
            if (currentNode->iPayload > currentNode->ptrNext->iPayload)
            {
                swapValue(currentNode->iPayload, currentNode->ptrNext->iPayload);
                bUnordered = 1;
            }

            currentNode = currentNode->ptrNext;
        }

        if (!bUnordered)
            break;

        nextNode = currentNode;
    }
}
