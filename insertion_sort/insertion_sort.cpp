#include "../sorting_methods.h"
#include "../functions_list/functions_list.h"
#include <iostream>
#include <cstdlib> //por vezes é necessário para o uso do malloc

using namespace std;

// Função para ordenar uma lista duplamente encadeada usando o método Insertion Sort
void insertionSort(Node* head)
{
    // Verifica se a lista está vazia ou tem apenas um elemento
    if (head == nullptr || head->ptrNext == nullptr)
        return;

    // Inicializa uma lista "ordenada" vazia e um ponteiro para o nó atual
    Node* sorted = nullptr;
    Node* current = head;

    // Percorre a lista original
    while (current != nullptr) 
    {
        // Salva o próximo nó para avançar na lista original
        Node* next = current->ptrNext;

        // Se a lista "ordenada" estiver vazia ou o elemento atual for menor que o primeiro elemento da lista "ordenada"
        if (sorted == nullptr || sorted->iPayload >= current->iPayload) 
        {
            // Insere o elemento atual no início da lista "ordenada"
            current->ptrNext = sorted;
            current->ptrPrev = nullptr;

            // Atualiza os ponteiros da lista "ordenada" e o elemento atual
            if (sorted != nullptr)
                sorted->ptrPrev = current;            
            sorted = current;
        } 
        else 
        {
            // Procura a posição correta na lista "ordenada" para inserir o elemento atual
            Node* search = sorted;
            while (search->ptrNext != nullptr && search->ptrNext->iPayload < current->iPayload) 
            {
                search = search->ptrNext;
            }

            // Insere o elemento atual na posição correta da lista "ordenada"
            current->ptrNext = search->ptrNext;
            if (search->ptrNext != nullptr)
                search->ptrNext->ptrPrev = current;
            search->ptrNext = current;
            current->ptrPrev = search;
        }

        // Avança para o próximo elemento da lista original
        current = next;
    }

    // Atualiza a cabeça da lista original
    while (sorted->ptrPrev != nullptr)
    {
        sorted = sorted->ptrPrev;
    }
    head = sorted;
}

// Função para ordenar uma lista duplamente encadeada usando o método Insertion Sort de forma otimizada
void optimizedInsertionSort(Node* head) 
{
    // Verifica se a lista está vazia ou tem apenas um elemento
    if (head == nullptr || head->ptrNext == nullptr)
        return;

    // Inicializa o ponteiro para o próximo nó após a cabeça da lista
    Node* current = head->ptrNext;

    // Percorre a lista a partir do segundo elemento
    while (current != nullptr) 
    {
        // Salva o valor do elemento atual
        int key = current->iPayload;

        // Inicializa o ponteiro para o nó anterior ao elemento atual
        Node* prev = current->ptrPrev;

        // Move os elementos maiores que o valor atual para a direita
        while (prev != nullptr && prev->iPayload > key) 
        {
            prev->ptrNext->iPayload = prev->iPayload;
            prev = prev->ptrPrev;
        }

        // Insere o valor atual na posição correta
        if (prev == nullptr)
            head->iPayload = key;
        else
            prev->ptrNext->iPayload = key;

        // Avança para o próximo elemento
        current = current->ptrNext;
    }
}
