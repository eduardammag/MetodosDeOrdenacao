#include "../sorting_methods.h"
#include "../functions_list/functions_list.h"
#include <iostream>
#include <cstdlib> //por vezes é necessário para o uso do malloc

using namespace std;

// Função para ordenar uma lista duplamente encadeada usando o método Selection Sort
void selectionSort(Node* head) 
{
    Node* current = head;
    while (current != nullptr) 
    {
        Node* innerCurrent = current->ptrNext;
        while (innerCurrent != nullptr) 
        {
            if (current->iPayload > innerCurrent->iPayload) 
            {
                swapValue(current->iPayload, innerCurrent->iPayload);
            }
            innerCurrent = innerCurrent->ptrNext;
        }
        current = current->ptrNext;
    }
}

// Função para ordenar uma lista duplamente encadeada usando o método Selection Sort de forma otimizada
void optimizedSelectionSort(Node* head) 
{
    Node* current = head;

    while (current != nullptr) 
    {
        Node* minNode = current;
        Node* innerCurrent = current->ptrNext;

        while (innerCurrent != nullptr) 
        {
            if (minNode->iPayload > innerCurrent->iPayload) 
            {
                minNode = innerCurrent;
            }
            innerCurrent = innerCurrent->ptrNext;
        }
        if (minNode != current) 
        {
            swapValue(current->iPayload, minNode->iPayload);
        }
        current = current->ptrNext;
    }
}
