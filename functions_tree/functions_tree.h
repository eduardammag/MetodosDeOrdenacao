#pragma once

using namespace std;

// Definição da estrutura de nó como um template
template <typename T>
struct Node
{
    T iPayload;
    Node* ptrLeft;
    Node* ptrRight;
    Node* next; // Ponteiro para o próximo nó na fila
};

// Declaração das funções como templates
template <typename T>
Node<T>* createNode(T);

template <typename T>
Node<T>* insertNode(Node<T>*, T);

template <typename T>
void bfsTraversal(Node<T>*);

template <typename T>
int treeHeight(Node<T>*);

template <typename T>
bool bfsSearch(Node<T>*, T);

template <typename T>
void enqueue(Node<T>*&, Node<T>*&, Node<T>*);

template <typename T>
Node<T>* dequeue(Node<T>*&, Node<T>*&);

#include "functions_tree.tpp"
