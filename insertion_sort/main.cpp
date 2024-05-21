#include "insertion_sort.h"
#include <iostream>
#include <fstream>
#include <cstdlib> //por vezes é necessário para o uso do malloc
#include <chrono> //para avaliar o desempenho do algoritmo
#include <ctime> //para gerar números aleatórios

using namespace std;
using namespace std::chrono;

int main()
{
    ofstream outFile("insertion_times.txt");

    if (!outFile) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
    
    Node* headGrades = nullptr;

    //Inserindo elementos na lista de notas (coloquei a lista já ordenada para testar se bagunça ou imprime ela como está)
    insertEnd(&headGrades, -1);
    insertEnd(&headGrades, 0);
    insertEnd(&headGrades, 2);
    insertEnd(&headGrades, 3);
    insertEnd(&headGrades, 4); 

    outFile << "Lista de notas original: "; 
    displayList(headGrades, outFile);
    outFile << endl;

    insertionSort(headGrades);

    outFile << "Lista de notas ordenada (Insertion Sort): "; 
    displayList(headGrades, outFile);
    outFile << endl;

    deleteList(&headGrades);

    outFile << "============================" << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headRandomNumbers = nullptr;

    //inserindo um exemplo de lista com valores em ordem aleatória
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

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Definindo variáveis para fazer o tempo gasto em média com cada função ao ordenar as lista abaixo
    long long llTotalInsertionSortTime = 0;
    long long llTotalOptimizedInsertionSortTime = 0;
    const int iNumLists = 4;
    const int iListSize = 15000;
    
    //Gerando listas aleatórias com uma quantidade grande de elementos a fim de comparar o tempo gasto com a ordenação de cada lista
    Node* headList1 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1 + rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList1, randomValue);
    }
    
    auto timeStart1 = high_resolution_clock::now();  //tempo antes de ordenar
    insertionSort(headList1);
    auto timeStop1 = high_resolution_clock::now();  //tempo depois de ordenar
    
    auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    llTotalInsertionSortTime += timeDuration1.count();
    outFile << "Tempo utilizado na ordenação da lista 1 (Insertion Sort): " << timeDuration1.count() << " nanosegundos." << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart2 = high_resolution_clock::now();  //tempo antes de ordenar
    optimizedInsertionSort(headList1);
    auto timeStop2 = high_resolution_clock::now();  //tempo depois de ordenar
    
    auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2);
    llTotalOptimizedInsertionSortTime += timeDuration2.count();
    outFile << "Tempo utilizado na ordenação da lista 1 (Optimized Insertion Sort): " << timeDuration2.count() << " nanosegundos." << endl;
    outFile << "============================" << endl;
    
    deleteList(&headList1);
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Node* headList2 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1 + rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList2, randomValue);
    }
    
    auto timeStart3 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    insertionSort(headList2);
    auto timeStop3 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration3 = duration_cast<nanoseconds>(timeStop3 - timeStart3);
    llTotalInsertionSortTime += timeDuration3.count();
    outFile << "Tempo utilizado na ordenação da lista 2 (Insertion Sort): " << timeDuration3.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart4 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedInsertionSort(headList2);
    auto timeStop4 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration4 = duration_cast<nanoseconds>(timeStop4 - timeStart4);
    llTotalOptimizedInsertionSortTime += timeDuration4.count();
    outFile << "Tempo utilizado na ordenação da lista 2 (Optimized Insertion Sort): " << timeDuration4.count() << " nanosegundos." << endl;
    outFile << "============================" << endl;
    
    deleteList(&headList2);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headList3 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1 + rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList3, randomValue);
    }
    
    auto timeStart5 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    insertionSort(headList3);
    auto timeStop5 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration5 = duration_cast<nanoseconds>(timeStop5 - timeStart5);
    llTotalInsertionSortTime += timeDuration5.count();
    outFile << "Tempo utilizado na ordenação da lista 3 (Insertion Sort): " << timeDuration5.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart6 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedInsertionSort(headList3);
    auto timeStop6 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration6 = duration_cast<nanoseconds>(timeStop6 - timeStart6);
    llTotalOptimizedInsertionSortTime += timeDuration6.count();
    outFile << "Tempo utilizado na ordenação da lista 3 (Optimized Insertion Sort): " << timeDuration6.count() << " nanosegundos." << endl;
    outFile << "============================" << endl;
    
    deleteList(&headList3);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headList4 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1 + rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList4, randomValue);
    }
    
    auto timeStart7 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    insertionSort(headList4);
    auto timeStop7 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration7 = duration_cast<nanoseconds>(timeStop7 - timeStart7);
    llTotalInsertionSortTime += timeDuration7.count();
    outFile << "Tempo utilizado na ordenação da lista 4 (Insertion Sort): " << timeDuration7.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart8 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedInsertionSort(headList4);
    auto timeStop8 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration8 = duration_cast<nanoseconds>(timeStop8 - timeStart8);
    llTotalOptimizedInsertionSortTime += timeDuration8.count();
    outFile << "Tempo utilizado na ordenação da lista 4 (Optimized Insertion Sort): " << timeDuration8.count() << " nanosegundos." << endl;
    outFile << "============================" << endl;
    
    deleteList(&headList4); 

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

    // Calculando a média dos tempos
    long long llAvgInsertionSortTime = llTotalInsertionSortTime / iNumLists;
    long long llAvgOptimizedInsertionSortTime = llTotalOptimizedInsertionSortTime / iNumLists;

    // Exibindo os resultados
    outFile << "Média do tempo utilizado na ordenação com Insertion Sort: " << llAvgInsertionSortTime << " nanosegundos." << endl;
    outFile << "Média do tempo utilizado na ordenação com Optimized Insertion Sort: " << llAvgOptimizedInsertionSortTime << " nanosegundos." << endl;

    return 0;
}
