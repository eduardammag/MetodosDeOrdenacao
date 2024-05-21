#include "selection_sort.h"
#include <iostream>
#include <cstdlib> //por vezes é necessário para o uso do malloc

using std::cout;
using std::endl;

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