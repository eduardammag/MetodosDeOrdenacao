#include "functions_tree.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Node* createNode(int iValue)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    
    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;
    tmp->next = nullptr; // Inicializa o ponteiro da fila
    
    return tmp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

void enqueue(Node*& front, Node*& rear, Node* treeNode)
{
    if (rear == nullptr)
    {
        front = rear = treeNode;
    }
    else
    {
        rear->next = treeNode;
        rear = treeNode;
    }
    treeNode->next = nullptr; // Garantir que o próximo nó seja nulo
}

Node* dequeue(Node*& front, Node*& rear)
{
    if (front == nullptr)
    {
        return nullptr;
    }

    Node* temp = front;
    front = front->next;

    if (front == nullptr)
    {
        rear = nullptr;
    }

    return temp;
}

void bfsTraversal(Node* startingNode)
{
    if (startingNode == nullptr) return;

    Node* queueFront = nullptr;
    Node* queueRear = nullptr;

    enqueue(queueFront, queueRear, startingNode);

    while (queueFront != nullptr)
    {
        Node* currentNode = dequeue(queueFront, queueRear);
        
        cout << currentNode->iPayload << " "; // Imprime o elemento

        if (currentNode->ptrLeft != nullptr)
        {
            enqueue(queueFront, queueRear, currentNode->ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {
            enqueue(queueFront, queueRear, currentNode->ptrRight);
        }
    }
}

bool bfsSearch(Node* startingNode, int value)
{
    if (startingNode == nullptr) return false;

    Node* queueFront = nullptr;
    Node* queueRear = nullptr;

    enqueue(queueFront, queueRear, startingNode);

    while (queueFront != nullptr)
    {
        Node* currentNode = dequeue(queueFront, queueRear);

        if (currentNode->iPayload == value)
        {
            return true;
        }

        if (currentNode->ptrLeft != nullptr)
        {
            enqueue(queueFront, queueRear, currentNode->ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {
            enqueue(queueFront, queueRear, currentNode->ptrRight);
        }
    }

    return false;
}

int treeHeight(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight = treeHeight(node->ptrLeft);
        int rightHeight = treeHeight(node->ptrRight);

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}
