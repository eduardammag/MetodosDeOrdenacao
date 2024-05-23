#include "../sorting_methods.h"
#include "../functions_list/functions_list.h"
#include <iostream>
#include <cstdlib> //por vezes é necessário para o uso do malloc

using namespace std;

template<typename T>
void bubbleSort(Node<T>* head)
{
    int length = 0;
    Node<T>* currentNode;
    Node<T>* nextNode = nullptr;

    // Calculando o comprimento da lista
    for (currentNode = head; currentNode != nullptr; currentNode = currentNode->ptrNext)
    {
        length++;
    }

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

template<typename T>
void optimizedBubbleSort(Node<T>* head)
{
    Node<T>* currentNode;
    Node<T>* nextNode = nullptr;
    int length = 0;

    // Calculando o comprimento da lista
    for (currentNode = head; currentNode != nullptr; currentNode = currentNode->ptrNext)
    {
        length++;
    }

    bool bUnordered = false;

    for (int i = 0; i < length - 1; ++i)
    {
        bUnordered = false;
        currentNode = head;

        while (currentNode->ptrNext != nextNode)
        {
            if (currentNode->iPayload > currentNode->ptrNext->iPayload)
            {
                swapValue(currentNode->iPayload, currentNode->ptrNext->iPayload);
                bUnordered = true;
            }

            currentNode = currentNode->ptrNext;
        }

        if (!bUnordered)
            break;

        nextNode = currentNode;
    }
}


