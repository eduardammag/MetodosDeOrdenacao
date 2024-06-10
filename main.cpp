#include "functions_list/functions_list.h"
#include "sorting_methods.h"

#include <iostream>
#include <fstream>
#include <cstdlib> // necessário para o uso do malloc
#include <chrono>  // para avaliar o desempenho do algoritmo
#include <ctime>   // para gerar números aleatórios

// Usando o namespace std para simplificar a utilização
using namespace std;
using namespace std::chrono;

int main()
{
    //CÓDIGO PARA SORTINGS
    
    ofstream outFile("sorting_times.txt");

    if (!outFile) 
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    // Lista de idades
    Node* headAges = nullptr;
    insertEnd(&headAges, 100);
    insertEnd(&headAges, 97);
    insertEnd(&headAges, 89);
    insertEnd(&headAges, 45);
    insertEnd(&headAges, 32);
    insertEnd(&headAges, 0);

    outFile << "Lista de idades original: "; 
    displayList(headAges, outFile);
    outFile << endl;

    bubbleSort(headAges);

    outFile << "Lista de idades ordenada (Bubble Sort): ";
    displayList(headAges, outFile);
    outFile << endl;

    deleteList(&headAges);
    outFile << "============================" << endl;

    // Lista de notas
    Node* headGrades = nullptr;
    insertEnd(&headGrades, -1);
    insertEnd(&headGrades, 0);
    insertEnd(&headGrades, 2);
    insertEnd(&headGrades, 3);
    insertEnd(&headGrades, 4); 

    outFile << "Lista de notas original: "; 
    displayList(headGrades, outFile);
    outFile << endl;

    selectionSort(headGrades);

    outFile << "Lista de notas ordenada (Selection Sort): "; 
    displayList(headGrades, outFile);
    outFile << endl;

    deleteList(&headGrades);
    outFile << "============================" << endl;

    // Lista de números aleatórios
    Node* headRandomNumbers = nullptr;
    insertEnd(&headRandomNumbers, -15);
    insertEnd(&headRandomNumbers, 27);
    insertEnd(&headRandomNumbers, 86);
    insertEnd(&headRandomNumbers, 3);
    insertEnd(&headRandomNumbers, 17); 

    outFile << "Lista de números aleatórios original: "; 
    displayList(headRandomNumbers, outFile);
    outFile << endl;

    insertionSort(headRandomNumbers);

    outFile << "Lista de números aleatórios ordenada (Insertion Sort): "; 
    displayList(headRandomNumbers, outFile);
    outFile << endl;

    deleteList(&headRandomNumbers);
    outFile << "============================" << endl;

    // Lista de idades
    Node* headAges2 = nullptr;
    insertEnd(&headAges2, 100);
    insertEnd(&headAges2, 89);
    insertEnd(&headAges2, 75);
    insertEnd(&headAges2, 43);
    insertEnd(&headAges2, 38);
    insertEnd(&headAges2, 0);

    outFile << "Lista de idades original: "; 
    displayList(headAges2, outFile);
    outFile << endl;

    countingSort(headAges2);

    outFile << "Lista de idades ordenada (Couting Sort): ";
    displayList(headAges2, outFile);
    outFile << endl;

    deleteList(&headAges2);
    outFile << "============================" << endl;
    
    ///////////////////////////////////////////////////////////////////////////////////

const int iNumLists = 1000;
    const int iListSize = 10000;

    long long llTotalBubbleSortTime = 0;
    long long llTotalOptimizedBubbleSortTime = 0;
    long long llTotalCountingSortTime = 0;
    long long llTotalInsertionSortTime = 0;
    long long llTotalOptimizedInsertionSortTime = 0;
    long long llTotalSelectionSortTime = 0;
    long long llTotalOptimizedSelectionSortTime = 0;

    srand(time(nullptr));

    auto measureAndLogTime = [&](void (*sortFunction)(Node*), const string& sortName, long long& totalTime, Node* list, int listNum) 
    {
        auto start = high_resolution_clock::now();
        sortFunction(list);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        totalTime += duration.count();
        outFile << "Lista " << listNum << " (" << sortName << "): " << duration.count() << " nanosegundos." << endl;
    };

    for (int listNum = 1; listNum <= iNumLists; ++listNum) 
    {
        Node* lists[7] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

        for (int i = 0; i < iListSize; ++i) 
        {
            int randomValue = 1 + rand() % 100;

            for (int j = 0; j < 7; ++j) 
            {
                insertEnd(&lists[j], randomValue);
            }
        }

        measureAndLogTime(bubbleSort, "Bubble Sort", llTotalBubbleSortTime, lists[0], listNum);
        measureAndLogTime(optimizedBubbleSort, "Optimized Bubble Sort", llTotalOptimizedBubbleSortTime, lists[1], listNum);
        measureAndLogTime(countingSort, "Counting Sort", llTotalCountingSortTime, lists[2], listNum);
        measureAndLogTime(insertionSort, "Insertion Sort", llTotalInsertionSortTime, lists[3], listNum);
        measureAndLogTime(optimizedInsertionSort, "Optimized Insertion Sort", llTotalOptimizedInsertionSortTime, lists[4], listNum);
        measureAndLogTime(selectionSort, "Selection Sort", llTotalSelectionSortTime, lists[5], listNum);
        measureAndLogTime(optimizedSelectionSort, "Optimized Selection Sort", llTotalOptimizedSelectionSortTime, lists[6], listNum);

        for (int j = 0; j < 7; ++j) 
        {
            deleteList(&lists[j]);
        }

        outFile << "============================" << endl;
    }

    long long llAvgBubbleSortTime = llTotalBubbleSortTime / iNumLists;
    long long llAvgOptimizedBubbleSortTime = llTotalOptimizedBubbleSortTime / iNumLists;
    long long llAvgCountingSortTime = llTotalCountingSortTime / iNumLists;
    long long llAvgInsertionSortTime = llTotalInsertionSortTime / iNumLists;
    long long llAvgOptimizedInsertionSortTime = llTotalOptimizedInsertionSortTime / iNumLists;
    long long llAvgSelectionSortTime = llTotalSelectionSortTime / iNumLists;
    long long llAvgOptimizedSelectionSortTime = llTotalOptimizedSelectionSortTime / iNumLists;

    outFile << "Média do tempo utilizado na ordenação com Bubble Sort: " << llAvgBubbleSortTime << " nanosegundos." << endl;
    outFile << "Média do tempo utilizado na ordenação com Optimized Bubble Sort: " << llAvgOptimizedBubbleSortTime << " nanosegundos." << endl;
    outFile << "Média do tempo utilizado na ordenação com Counting Sort: " << llAvgCountingSortTime << " nanosegundos." << endl;
    outFile << "Média do tempo utilizado na ordenação com Insertion Sort: " << llAvgInsertionSortTime << " nanosegundos." << endl;
    outFile << "Média do tempo utilizado na ordenação com Optimized Insertion Sort: " << llAvgOptimizedInsertionSortTime << " nanosegundos." << endl;
    outFile << "Média do tempo utilizado na ordenação com Selection Sort: " << llAvgSelectionSortTime << " nanosegundos." << endl;
    outFile << "Média do tempo utilizado na ordenação com Optimized Selection Sort: " << llAvgOptimizedSelectionSortTime << " nanosegundos." << endl;

    outFile.close();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //CÓDIGO PARA ÁRVORES
    
    NodeTree<int>* root0 = nullptr;
    
    root0 = insertNodeTree(root0, 42);
    root0 = insertNodeTree(root0, 14);
    root0 = insertNodeTree(root0, 11);
    root0 = insertNodeTree(root0, 10);
    root0 = insertNodeTree(root0, 100);
    root0 = insertNodeTree(root0, 57);
    root0 = insertNodeTree(root0, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal(root0);
    cout << endl;
    
    cout << "Tentativa de encontrar o 171 na árvore (nó existente): ";
    searchBFS(root0, 171);
    cout << endl;
    
    cout << "Tentativa de encontrar o 870 na árvore (nó não existente): ";
    searchBFS(root0, 870);
    cout << endl;
    
    cout << "Usando o DFS para encontrar 10 (nó existente): ";
    searchDFS(root0, 10);
    cout << endl;
    
    cout << "Tree Height: " << treeHeight(root0) << endl;

    
    ofstream outFile("tree_and_linked_list_times.txt");

    if (!outFile) 
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
    
    // Número de listas a serem criadas
    const int NUM_LISTS = 10;
    // Tamanho de cada lista
    const int SIZE = 1000;

    // Criação das listas e árvores e medição de tempo
    for (int j = 0; j < NUM_LISTS; ++j) 
    {
        // Gerar uma lista de números aleatórios
        int randomNumbers[SIZE];
        srand(time(nullptr)); // Inicializar a semente aleatória com o tempo atual
        for (int i = 0; i < SIZE; ++i) {
            randomNumbers[i] = rand() % 1000; // Números aleatórios entre 0 e 999
        }

        // Exemplo de criação de árvore e medição do tempo
        NodeTree<int>* root = nullptr;
        auto startTree = high_resolution_clock::now();
        for (int i = 0; i < SIZE; ++i) {
            insertNodeTree(root, randomNumbers[i]);
        }
        auto stopTree = high_resolution_clock::now();
        auto durationTree = duration_cast<nanoseconds>(stopTree - startTree);
        outFile << "Tempo de criação da árvore " << j + 1 << ": " << durationTree.count() << " nanoseconds" << endl;

        // Exemplo de criação de lista e medição do tempo
        Node<int>* head = nullptr;
        auto startList = high_resolution_clock::now();
        for (int i = 0; i < SIZE; ++i) {
            insertEnd(&head, randomNumbers[i]);
        }
        auto stopList = high_resolution_clock::now();
        auto durationList = duration_cast<nanoseconds>(stopList - startList);
        outFile << "Tempo de criação da lista " << j + 1 << ": " << durationList.count() << " nanoseconds" << endl;

        // Exemplo de busca em árvore utilizando DFS e BFS e medição do tempo
        // Utilize o mesmo conjunto de números aleatórios para cada iteração
        int valueToSearch = randomNumbers[rand() % SIZE]; // Escolhe um valor aleatório da lista para buscar

        // Medição de tempo para DFS
        auto startDFS = high_resolution_clock::now();
        searchDFS(root, valueToSearch);
        auto stopDFS = high_resolution_clock::now();
        auto durationDFS = duration_cast<nanoseconds>(stopDFS - startDFS);
        outFile << "Tempo de busca com DFS na árvore " << j + 1 << ": " << durationDFS.count() << " nanoseconds" << endl;

        // Medição de tempo para BFS
        auto startBFS = high_resolution_clock::now();
        searchBFS(root, valueToSearch);
        auto stopBFS = high_resolution_clock::now();
        auto durationBFS = duration_cast<nanoseconds>(stopBFS - startBFS);
        outFile << "Tempo de busca com BFS na árvore " << j + 1 << ": " << durationBFS.count() << " nanoseconds" << endl;
        
        outFile << "==========================================" << endl;
    }

    outFile.close();

    return 0;
}
