#include "counting_sort.h"
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
    ofstream outFile("counting_times.txt");

    if (!outFile) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
    
    // Testando se a função está ordenando corretamente
    Node* headAges = nullptr;

    // Inserindo elementos na lista de idades (ordenei a lista com o pior caso, ou seja, de forma decrescente)
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

    // Ordenando a lista usando Counting Sort
    countingSort(headAges, iAgesSize);

    outFile << "Lista de idades ordenada (Counting Sort): "; 
    displayList(headAges, outFile);
    outFile << endl;

    // Limpando a lista
    deleteList(&headAges);

    outFile << "============================" << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headGrades = nullptr;

    // Inserindo elementos na lista de notas (coloquei a lista já ordenada para testar se bagunça ou imprime ela como está)
    insertEnd(&headGrades, -1);
    insertEnd(&headGrades, 0);
    insertEnd(&headGrades, 2);
    insertEnd(&headGrades, 3);
    insertEnd(&headGrades, 4); 

    int iGradesSize = 5;

    outFile << "Lista de notas original: "; 
    displayList(headGrades, outFile);
    outFile << endl;

    // Ordenando a lista usando Counting Sort
    countingSort(headGrades, iGradesSize);

    outFile << "Lista de notas ordenada (Counting Sort): "; 
    displayList(headGrades, outFile);
    outFile << endl;

    // Limpando a lista
    deleteList(&headGrades);

    outFile << "============================" << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headRandomNumbers = nullptr;

    // Inserindo números aleatórios na lista
    insertEnd(&headRandomNumbers, -15);
    insertEnd(&headRandomNumbers, 27);
    insertEnd(&headRandomNumbers, 86);
    insertEnd(&headRandomNumbers, 3);
    insertEnd(&headRandomNumbers, 17); 

    int iRandomNumbersSize = 5;

    outFile << "Lista de números aleatórios original: "; 
    displayList(headRandomNumbers, outFile);
    outFile << endl;  

    // Ordenando a lista usando Counting Sort
    countingSort(headRandomNumbers, iRandomNumbersSize);

    outFile << "Lista de números aleatórios ordenada (Counting Sort): "; 
    displayList(headRandomNumbers, outFile);
    outFile << endl;

    // Limpando a lista
    deleteList(&headRandomNumbers);

    outFile << "============================" << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Definindo variáveis para medir o tempo gasto com cada função ao ordenar as listas abaixo
    long long llTotalCountingSortTime = 0;
    const int iNumLists = 4;
    const int iListSize = 15000;
    
    // Gerando listas aleatórias com uma quantidade grande de elementos para comparar o tempo gasto com a ordenação de cada lista
    Node* headList1 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos na lista duplamente encadeada
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1 + rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList1, randomValue);
    }
    
    // Medindo o tempo antes e depois de ordenar a lista
    auto timeStart1 = high_resolution_clock::now();  
    countingSort(headList1, iListSize);
    auto timeStop1 = high_resolution_clock::now();  
    
    auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    llTotalCountingSortTime += timeDuration1.count();
    outFile << "Tempo utilizado na ordenação da lista 1 (Counting Sort): " << timeDuration1.count() << " nanosegundos." << endl;

    outFile << "============================" << endl;
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Node* headList2 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos na lista duplamente encadeada
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1 + rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList2, randomValue);
    }
    
    // Medindo o tempo antes e depois de ordenar a lista
    auto timeStart3 = high_resolution_clock::now();  
    countingSort(headList2, iListSize);
    auto timeStop3 = high_resolution_clock::now();  
    
    auto timeDuration3 = duration_cast<nanoseconds>(timeStop3 - timeStart3);
    llTotalCountingSortTime += timeDuration3.count();
    outFile << "Tempo utilizado na ordenação da lista 2 (Counting Sort): " << timeDuration3.count() << " nanosegundos." << endl;

    outFile << "============================" << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headList3 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos na lista duplamente encadeada
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1 + rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList3, randomValue);
    }
    
    // Medindo o tempo antes e depois de ordenar a lista
    auto timeStart5 = high_resolution_clock::now();  
    countingSort(headList3, iListSize);
    auto timeStop5 = high_resolution_clock::now();  
    
    auto timeDuration5 = duration_cast<nanoseconds>(timeStop5 - timeStart5);
    llTotalCountingSortTime += timeDuration5.count();
    outFile << "Tempo utilizado na ordenação da lista 3 (Counting Sort): " << timeDuration5.count() << " nanosegundos." << endl;

    outFile << "============================" << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headList4 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos na lista duplamente encadeada
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = 1 + rand() % 100; // Gera um número aleatório entre 1 e 100
        insertEnd(&headList4, randomValue);
    }
    
    // Medindo o tempo antes e depois de ordenar a lista
    auto timeStart7 = high_resolution_clock::now();  
    countingSort(headList4, iListSize);
    auto timeStop7 = high_resolution_clock::now();  
    
    auto timeDuration7 = duration_cast<nanoseconds>(timeStop7 - timeStart7);
    llTotalCountingSortTime += timeDuration7.count();
    outFile << "Tempo utilizado na ordenação da lista 4 (Counting Sort): " << timeDuration7.count() << " nanosegundos." << endl;

    outFile << "============================" << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

    // Calculando a média dos tempos
    long long llAvgCountingSortTime = llTotalCountingSortTime / iNumLists;

    // Exibindo os resultados
    outFile << "Média do tempo utilizado na ordenação com Counting Sort: " << llAvgCountingSortTime << " nanosegundos." << endl;

    outFile << "============================" << endl;

    return 0;
}
