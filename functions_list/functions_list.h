#pragma once
#include <fstream>
#include <ostream>
using namespace std;

// Definição de estrutura para os nós da lista duplamente encadeada
template<typename T>
struct Node
{
    T payLoad;
    Node<T>* ptrNext;  
    Node<T>* ptrPrev;
};

// Protótipos das funções "base" de listas duplamente encadeadas
template<typename T>
Node<T>* createNode(T);

template<typename T>
void displayList(Node<T>*, ostream&);

template<typename T>
void insertEnd(Node<T>**, T);

template<typename T>
void deleteNode(Node<T>**, Node<T>*);

template<typename T>
void deleteList(Node<T>**);

template<typename T>
void swapValue(T&, T&);

// Inclui a implementação das funções template
#include "functions_list.tpp"

template<typename T>
void deleteList(Node<T>**);

template<typename T>
void swapValue(T&, T&);
