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
    //testando se as funções estão ordenando corretamente
    Node* headAges = nullptr;

    //Inserindo elementos na lista de idades (ordenei a lista com o pior caso, ou seja, de forma decrescente)
    insertEnd(&headAges, 100);
    insertEnd(&headAges, 97);
    insertEnd(&headAges, 89);
    insertEnd(&headAges, 45);
    insertEnd(&headAges, 32);
    insertEnd(&headAges, 0);

    int iAgesSize = 6;

    outFile << "Lista de idades original: "; 
    displayList(headAges, outFile);
    outFile << endl; 

    bubbleSort(headAges, iAgesSize);

    outFile << "Lista de idades ordenada (Bubble Sort): "; 
    displayList(headAges, outFile);
    outFile << endl;

    deleteList(&headAges);

    outFile << "============================" << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headGrades = nullptr;

    //Inserindo elementos na lista de notas (coloquei a lista já ordenada para testar se bagunça ou imprime ela como está)
    insertEnd(&headGrades, -1);
    insertEnd(&headGrades, 0);
    insertEnd(&headGrades, 2);
    insertEnd(&headGrades, 3);
    insertEnd(&headGrades, 4); 

    int iGradesSize = 5;

    outFile << "Lista de notas original: "; 
    displayList(headGrades, outFile);
    outFile << endl;

    bubbleSort(headGrades, iGradesSize);

    outFile << "Lista de notas ordenada (Bubble Sort): "; 
    displayList(headGrades, outFile);
    outFile << endl;

    deleteList(&headGrades);

    outFile << "============================" << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headRandomNumbers = nullptr;

    insertEnd(&headRandomNumbers, -15);
    insertEnd(&headRandomNumbers, 27);
    insertEnd(&headRandomNumbers, 86);
    insertEnd(&headRandomNumbers, 3);
    insertEnd(&headRandomNumbers, 17); 

    int iRandomNumbersSize = 5;

    outFile << "Lista de números aleatórios original: "; 
    displayList(headRandomNumbers, outFile);
    outFile << endl; 

    bubbleSort(headRandomNumbers, iRandomNumbersSize);

    outFile << "Lista de números aleatórios ordenada (Bubble Sort): "; 
    displayList(headRandomNumbers, outFile);
    outFile << endl;

    deleteList(&headRandomNumbers);

    outFile << "============================" << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const int iNumLists = 1000;
    const int iListSize = 10000;

    // Definindo variáveis para o tempo total de execução de cada algoritmo
    long long llTotalBubbleSortTime = 0;
    long long llTotalOptimizedBubbleSortTime = 0;
    long long llTotalCountingSortTime = 0;
    long long llTotalInsertionSortTime = 0;
    long long llTotalOptimizedInsertionSortTime = 0;
    long long llTotalSelectionSortTime = 0;
    long long llTotalOptimizedSelectionSortTime = 0;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    for (int listNum = 1; listNum <= iNumLists; ++listNum) 
    {
        Node* lists[7] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

        // Gerando listas idênticas com elementos aleatórios
        for (int i = 0; i < iListSize; ++i) 
        {
            int randomValue = 1 + rand() % 100;
            for (int j = 0; j < 7; ++j) 
            {
                insertEnd(&lists[j], randomValue);
            }
        }

        // Função auxiliar para medir e registrar o tempo
        auto measureAndLogTime = [&](void (*sortFunction)(Node*, int), const string& sortName, long long& totalTime, Node* list) 
        {
            auto start = high_resolution_clock::now();
            sortFunction(list, iListSize);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            totalTime += duration.count();
            outFile << "Lista " << listNum << " (" << sortName << "): " << duration.count() << " nanosegundos." << endl;
        };

        measureAndLogTime(bubbleSort, "Bubble Sort", llTotalBubbleSortTime, lists[0]);
        measureAndLogTime(optimizedBubbleSort, "Optimized Bubble Sort", llTotalOptimizedBubbleSortTime, lists[1]);
        measureAndLogTime(countingSort, "Counting Sort", llTotalCountingSortTime, lists[2]);
        measureAndLogTime(insertionSort, "Insertion Sort", llTotalInsertionSortTime, lists[3]);
        measureAndLogTime(optimizedInsertionSort, "Optimized Insertion Sort", llTotalOptimizedInsertionSortTime, lists[4]);
        measureAndLogTime(selectionSort, "Selection Sort", llTotalSelectionSortTime, lists[5]);
        measureAndLogTime(optimizedSelectionSort, "Optimized Selection Sort", llTotalOptimizedSelectionSortTime, lists[6]);

        // Deletando listas
        for (int j = 0; j < 7; ++j) 
        {
            deleteList(&lists[j]);
        }

        outFile << "============================" << endl;
    }

    // Calculando a média dos tempos
    long long llAvgBubbleSortTime = llTotalBubbleSortTime / iNumLists;
    long long llAvgOptimizedBubbleSortTime = llTotalOptimizedBubbleSortTime / iNumLists;
    long long llAvgCountingSortTime = llTotalCountingSortTime / iNumLists;
    long long llAvgInsertionSortTime = llTotalInsertionSortTime / iNumLists;
    long long llAvgOptimizedInsertionSortTime = llTotalOptimizedInsertionSortTime / iNumLists;
    long long llAvgSelectionSortTime = llTotalSelectionSortTime / iNumLists;
    long long llAvgOptimizedSelectionSortTime = llTotalOptimizedSelectionSortTime / iNumLists;

    // Exibindo os resultados
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