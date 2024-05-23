#include "../sorting_methods.h"
#include "../functions_list/functions_list.h"
#include <iostream>
#include <cstdlib> //por vezes é necessário para o uso do malloc

using namespace std;

template<typename T>
void selectionSort(Node<T>* head) 
{
    Node<T>* current = head;
    while (current != nullptr) 
    {
        Node<T>* innerCurrent = current->ptrNext;
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

template<typename T>
void optimizedSelectionSort(Node<T>* head) 
{
    Node<T>* current = head;

    while (current != nullptr) 
    {
        Node<T>* minNode = current;
        Node<T>* innerCurrent = current->ptrNext;

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

