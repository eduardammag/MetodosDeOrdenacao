#include "functionsTree.h"

#include <iostream>

using namespace std;

int main()
{
    NodeTree<int>* root = nullptr;
    
    root = insertNodeTree(root, 42);
    root = insertNodeTree(root, 14);
    root = insertNodeTree(root, 11);
    root = insertNodeTree(root, 10);
    root = insertNodeTree(root, 100);
    root = insertNodeTree(root, 57);
    root = insertNodeTree(root, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;
    
    cout << "Tentativa de encontrar o 171 na árvore (nó existente): ";
    searchBFS(root, 171);
    cout << endl;
    
    cout << "Tentativa de encontrar o 870 na árvore (nó não existente): ";
    searchBFS(root, 870);
    cout << endl;
    
    cout << "Tree Height: " << treeHeight(root) << endl;

    return 0;
}
