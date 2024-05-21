#pragma once

//Protótipos das funções
Node* createNode(int);
void displayList(Node*, ostream&);
void insertEnd(Node**, int);
void deleteNode(Node**, Node*);
void deleteList(Node**);
void swapValue(int&, int&);
void bubbleSort(Node*, int);
void optimizedBubbleSort(Node*, int);
