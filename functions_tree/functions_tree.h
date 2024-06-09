#pragma once
using namespace std;

template<typename T>
struct NodeTree
{
    T payLoad;
    NodeTree* ptrLeft;
    NodeTree* ptrRight;
};

template<typename T>
NodeTree<T>* createNodeTree(T);

template<typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>*, T);

template<typename T>
void bfsTraversal(NodeTree<T>*);

template<typename T>
int treeHeight(NodeTree<T>*);

// Inclui a implementação das funções template
#include "functionsTree.tpp"
