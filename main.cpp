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

    const int numLists = 1000;
    const int listSize = 10000;
    
    srand(time(nullptr));

    for (int i = 0; i < numLists; ++i) {
        Node* head = nullptr;

        for (int j = 0; j < listSize; ++j) {
            int randomValue = 1 + rand() % 100;
            insertEnd(&head, randomValue);
        }

        outFile << "Lista " << i + 1 << " gerada." << std::endl;

        // Medir o tempo de Bubble Sort
        Node* headCopy = copyList(head);
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(headCopy);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        outFile << "Tempo utilizado na ordenação da lista " << i + 1 << " (Bubble Sort): " << duration.count() << " nanosegundos." << std::endl;
        deleteList(&headCopy);

        // Medir o tempo de Optimized Bubble Sort
        headCopy = copyList(head);
        start = std::chrono::high_resolution_clock::now();
        optimizedBubbleSort(headCopy);
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        outFile << "Tempo utilizado na ordenação da lista " << i + 1 << " (Optimized Bubble Sort): " << duration.count() << " nanosegundos." << std::endl;
        deleteList(&headCopy);

        // Medir o tempo de Counting Sort
        headCopy = copyList(head);
        start = std::chrono::high_resolution_clock::now();
        countingSort(headCopy);
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        outFile << "Tempo utilizado na ordenação da lista " << i + 1 << " (Counting Sort): " << duration.count() << " nanosegundos." << std::endl;
        deleteList(&headCopy);

        // Medir o tempo de Insertion Sort
        headCopy = copyList(head);
        start = std::chrono::high_resolution_clock::now();
        insertionSort(headCopy);
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        outFile << "Tempo utilizado na ordenação da lista " << i + 1 << " (Insertion Sort): " << duration.count() << " nanosegundos." << std::endl;
        deleteList(&headCopy);

        // Medir o tempo de Optimized Insertion Sort
        headCopy = copyList(head);
        start = std::chrono::high_resolution_clock::now();
        optimizedInsertionSort(headCopy);
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        outFile << "Tempo utilizado na ordenação da lista " << i + 1 << " (Optimized Insertion Sort): " << duration.count() << " nanosegundos." << std::endl;
        deleteList(&headCopy);

        // Medir o tempo de Selection Sort
        headCopy = copyList(head);
        start = std::chrono::high_resolution_clock::now();
        selectionSort(headCopy);
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        outFile << "Tempo utilizado na ordenação da lista " << i + 1 << " (Selection Sort): " << duration.count() << " nanosegundos." << std::endl;
        deleteList(&headCopy);

        // Medir o tempo de Optimized Selection Sort
        headCopy = copyList(head);
        start = std::chrono::high_resolution_clock::now();
        optimizedSelectionSort(headCopy);
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        outFile << "Tempo utilizado na ordenação da lista " << i + 1 << " (Optimized Selection Sort): " << duration.count() << " nanosegundos." << std::endl;
        deleteList(&headCopy);

        outFile << "============================" << std::endl;

        deleteList(&head);
    }
}