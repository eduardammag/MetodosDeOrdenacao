#include <iostream>
#include <cstdlib>
#include "functionsTree.h"
#include "functions_list.h"
using namespace std;

template<typename T>
NodeTree<T>* createNodeTree(T data)
{
    NodeTree<T>* temp = (NodeTree<T>*) malloc(sizeof(NodeTree<T>));
    
    if (temp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    temp->payLoad = data;  // Corrigido de iPayload para payLoad
    temp->ptrLeft = nullptr;
    temp->ptrRight = nullptr;
    
    return temp;
}

template<typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>* startingNode, T data)
{
    if(startingNode == nullptr)
    {
        return createNodeTree(data);
    }
    
    if(data < startingNode->payLoad)
    {
        startingNode->ptrLeft = insertNodeTree(startingNode->ptrLeft, data);
    }
    else
    {
        startingNode->ptrRight = insertNodeTree(startingNode->ptrRight, data);
    }
    
    return startingNode;
}

template<typename T>
void bfsTraversal(NodeTree<T>* startingNode)
{
    if (startingNode == nullptr) return;

    Node<NodeTree<T>*>* head = nullptr;
    Node<NodeTree<T>*>* currentNode = nullptr;

    insertEnd(&head, startingNode);

    currentNode = head;

    bool firstElement = true;

    while (currentNode != nullptr)
    {   
        NodeTree<T>* treeNode = currentNode->payLoad;

        if (!firstElement)
        {
            cout << ", ";
        }
        cout << treeNode->payLoad;
        firstElement = false;

        if (treeNode->ptrLeft != nullptr)
        {
            insertEnd(&head, treeNode->ptrLeft);
        }

        if (treeNode->ptrRight != nullptr)
        {
            insertEnd(&head, treeNode->ptrRight);
        }

        currentNode = currentNode->ptrNext;
    }

    cout << endl;
}

template<typename T>
NodeTree<T>* searchBFS(NodeTree<T>* startingNode, T value)
{
    if (startingNode == nullptr) return nullptr;

    Node<NodeTree<T>*>* head = nullptr;
    Node<NodeTree<T>*>* currentNode = nullptr;

    insertEnd(&head, startingNode);

    currentNode = head;

    while (currentNode != nullptr)
    {   
        NodeTree<T>* treeNode = currentNode->payLoad;

        if (treeNode->payLoad == value) {
            cout << "Este nó foi encontrado e se encontra no endereço: " << treeNode << endl;
            return treeNode;
        }

        if (treeNode->ptrLeft != nullptr)
        {
            insertEnd(&head, treeNode->ptrLeft);
        }

        if (treeNode->ptrRight != nullptr)
        {
            insertEnd(&head, treeNode->ptrRight);
        }

        currentNode = currentNode->ptrNext;
    }

    cout << "Não foi possível achar esse valor na árvore." << endl;
    return nullptr;
}


template<typename T>
int treeHeight(NodeTree<T>* startingNode)
{
    if (startingNode == nullptr) return 0;
    else
    {
        int leftHeight = treeHeight(startingNode->ptrLeft);
        int rightHeight = treeHeight(startingNode->ptrRight);

        return max(leftHeight, rightHeight) + 1;
    }
}
