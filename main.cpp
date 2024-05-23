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

    return 0;
}
