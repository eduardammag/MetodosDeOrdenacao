#pragma once

#include <fstream>
#include <ostream>
using namespace std;

// Definição de estrutura para os nós da lista duplamente encadeada
typedef struct Node
{
    int iPayload;
    Node* ptrNext;  
    Node* ptrPrev;
} Node;

// Protótipos das funções "base" de listas duplamente encadeadas
Node* createNode(int);
void displayList(Node*, ostream&);
void insertEnd(Node**, int);
void deleteNode(Node**, Node*);
void deleteList(Node**);
void swapValue(int&, int&);