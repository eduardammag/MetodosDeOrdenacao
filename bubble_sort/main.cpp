#include "bubble_sort.h"
#include <iostream>
#include <fstream>
#include <cstdlib> //por vezes é necessário para o uso do malloc
#include <chrono> //para avaliar o desempenho do algoritmo
#include <ctime> //para gerar números aleatórios

using std::cout;
using std::endl;
using std::ostream;
using std::ofstream;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main()
{
    ofstream outFile("bubble_times.txt");

    if (!outFile) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
    //testando se a função está ordenando corretamente
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

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Definindo variáveis para fazer o tempo gasto em média com cada função ao ordenar as lista abaixo
    long long llTotalBubbleSortTime = 0;
    long long llTotalOptimizedBubbleSortTime = 0;
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
    bubbleSort(headList1, iListSize);
    auto timeStop1 = high_resolution_clock::now();  //tempo depois de ordenar
    
    auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    llTotalBubbleSortTime += timeDuration1.count();
    outFile << "Tempo utilizado na ordenação da lista 1 (Bubble Sort): " << timeDuration1.count() << " nanosegundos." << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart2 = high_resolution_clock::now();  //tempo antes de ordenar
    optimizedBubbleSort(headList1, iListSize);
    auto timeStop2 = high_resolution_clock::now();  //tempo depois de ordenar
    
    auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2);
    llTotalOptimizedBubbleSortTime += timeDuration2.count();
    outFile << "Tempo utilizado na ordenação da lista 1 (Optimized Bubble Sort): " << timeDuration2.count() << " nanosegundos." << endl;
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
    bubbleSort(headList2, iListSize);
    auto timeStop3 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration3 = duration_cast<nanoseconds>(timeStop3 - timeStart3);
    llTotalBubbleSortTime += timeDuration3.count();
    outFile << "Tempo utilizado na ordenação da lista 2 (Bubble Sort): " << timeDuration3.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart4 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedBubbleSort(headList2, iListSize);
    auto timeStop4 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration4 = duration_cast<nanoseconds>(timeStop4 - timeStart4);
    llTotalOptimizedBubbleSortTime += timeDuration4.count();
    outFile << "Tempo utilizado na ordenação da lista 2 (Optimized Bubble Sort): " << timeDuration4.count() << " nanosegundos." << endl;
    outFile << "============================" << endl;
    
    deleteList(&headList2);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headList3 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1+ rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList3, randomValue);
    }
    
    auto timeStart5 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    bubbleSort(headList3, iListSize);
    auto timeStop5 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration5 = duration_cast<nanoseconds>(timeStop5 - timeStart5);
    llTotalBubbleSortTime += timeDuration5.count();
    outFile << "Tempo utilizado na ordenação da lista 3 (Bubble Sort): " << timeDuration5.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart6 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedBubbleSort(headList3, iListSize);
    auto timeStop6 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration6 = duration_cast<nanoseconds>(timeStop6 - timeStart6);
    llTotalOptimizedBubbleSortTime += timeDuration6.count();
    outFile << "Tempo utilizado na ordenação da lista 3 (Optimized Bubble Sort): " << timeDuration6.count() << " nanosegundos." << endl;
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
    bubbleSort(headList4, iListSize);
    auto timeStop7 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration7 = duration_cast<nanoseconds>(timeStop7 - timeStart7);
    llTotalBubbleSortTime += timeDuration7.count();
    outFile << "Tempo utilizado na ordenação da lista 4 (Bubble Sort): " << timeDuration7.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart8 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedBubbleSort(headList4, iListSize);
    auto timeStop8 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration8 = duration_cast<nanoseconds>(timeStop8 - timeStart8);
    llTotalOptimizedBubbleSortTime += timeDuration8.count();
    outFile << "Tempo utilizado na ordenação da lista 4 (Optimized Bubble Sort): " << timeDuration8.count() << " nanosegundos." << endl;
    outFile << "============================" << endl;
    
    deleteList(&headList4); 

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

    // Calculando a média dos tempos
    long long llAvgBubbleSortTime = llTotalBubbleSortTime / iNumLists;
    long long llAvgOptimizedBubbleSortTime = llTotalOptimizedBubbleSortTime / iNumLists;

    // Exibindo os resultados
    outFile << "Média do tempo utilizado na ordenação com Bubble Sort: " << llAvgBubbleSortTime << " nanosegundos." << endl;
    outFile << "Média do tempo utilizado na ordenação com Optimized Bubble Sort: " << llAvgOptimizedBubbleSortTime << " nanosegundos." << endl;

    return 0;
}
