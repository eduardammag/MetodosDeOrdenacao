#include "insertion_sort.h"
#include <iostream>
#include <cstdlib> //por vezes é necessário para o uso do malloc

using namespace std;
using namespace std::chrono;

// Função para criar um novo nó com um inteiro fornecido
Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
}

// Função para exibir os elementos da lista
void displayList(Node* node, ostream& os)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return; // Sai da função se a lista estiver vazia
    }
    
    if  (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return; // Sai da função se o nó não for o primeiro na lista
       
    }
    
    Node* currentNode = node;
     
    while (currentNode != nullptr)
    {
        os << currentNode->iPayload << " ";
        currentNode = currentNode->ptrNext;
    }
    os << endl;
}

// Função para inserir um novo nó no final da lista
void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);  // Cria um novo nó com o inteiro fornecido
    
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }
    
    Node* temp = (*head);
    
    // Percorre a lista até o fim
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;
    
    newNode->ptrPrev = temp;   // O novo nó aponta para o último nó da lista
    temp->ptrNext = newNode;   // O último nó da lista aponta para o novo nó
}

// Função para remover um nó específico da lista
void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }
    
    // Se o nó a ser removido for o primeiro nó da lista, atualiza a cabeça da lista
    if (*head == ptrDelete) (*head) = ptrDelete->ptrNext;
    
    // Se o nó a ser removido não for o último nó da lista, atualiza o ponteiro do nó posterior ao nó a ser removido
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    
    // Se o nó a ser removido não for o primeiro nó da lista, atualiza o ponteiro do nó anterior ao nó a ser removido
    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    
    free(ptrDelete);  // Libera a memória alocada para o nó a ser removido
}

void deleteList(Node** head)
{
    Node* current = *head;
    Node* next;

    while (current != nullptr)
    {
        next = current->ptrNext;
        free(current);
        current = next;
    }

    *head = nullptr; // Atualiza a cabeça da lista para nullptr
}

//função para trocar dois valores
void swapValue(int& iValue_1, int& iValue_2)
{
    int iTemp = iValue_1;
    iValue_1 = iValue_2;
    iValue_2 = iTemp;
}

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
