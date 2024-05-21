#pragma once

#include <fstream>
using namespace std;
using std::ostream;
using std::ofstream;

// Definição de estrutura para os nós da lista duplamente encadeada
typedef struct Node
{
    int iPayload;   // Dados armazenados no nó
    Node* ptrNext;  // Ponteiro para o próximo nó na lista
    Node* ptrPrev;  // Ponteiro para o nó anterior na lista
} Node;

//Protótipos das funções
Node* createNode(int);
void displayList(Node*, ostream&);
void insertEnd(Node**, int);
void deleteNode(Node**, Node*);
void deleteList(Node**);
void swapValue(int&, int&);
void selectionSort(Node*);
void optimizedSelectionSort(Node*);
