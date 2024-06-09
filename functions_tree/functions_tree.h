#pragma once

using namespace std;

typedef struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
    Node* next; // Ponteiro para o próximo nó na fila
} Node;

Node* createNode(int);

Node* insertNode(Node*, int);

void bfsTraversal(Node*);

int treeHeight(Node*);

bool bfsSearch(Node*, int);

void enqueue(Node*&, Node*&, Node*);

Node* dequeue(Node*&, Node*&);
