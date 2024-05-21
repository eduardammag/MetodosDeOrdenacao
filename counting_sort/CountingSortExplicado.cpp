#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para imprimir o estado atual do vetor
void printArray(const vector<int>& arr, const string& msg) {
    cout << msg << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void countingSortVerbose(vector<int>& arr) {
    // Encontrar o maior valor no vetor
    int max_val = *max_element(arr.begin(), arr.end());
    cout << "Maior valor no vetor: " << max_val << endl;

    // Criar um vetor de contagem com tamanho suficiente para armazenar contagens de 0 até max_val
    vector<int> count(max_val + 1, 0);
    printArray(count, "Vetor de contagem inicial");

    // Contar a ocorrência de cada elemento no vetor original
    for (int num : arr) {
        count[num]++;
        printArray(count, "Incrementando count[" + to_string(num) + "]");
    }

    // Modificar o vetor de contagem para armazenar as posições dos elementos na saída
    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
        printArray(count, "Atualizando count[" + to_string(i) + "]");
    }

    // Criar um vetor de saída que será ordenado
    vector<int> output(arr.size(), 0);
    printArray(output, "Vetor de saída inicial");

    // Construir o vetor de saída
    for (int i = arr.size() - 1; i >= 0; i--) {
        int num = arr[i];
        output[count[num] - 1] = num;
        count[num]--;
        printArray(output, "Colocando " + to_string(num) + " na posição " + to_string(count[num]));
        printArray(count, "Decrementando count[" + to_string(num) + "]");
    }

    // Copiar o vetor de saída para o vetor original
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
        printArray(arr, "Copiando de volta para arr[" + to_string(i) + "]");
    }
}

int main() {
    // Definindo o vetor original
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    printArray(arr, "Vetor original");
    
    // Chamando a função de Counting Sort com verbose
    countingSortVerbose(arr);
    
    // Imprimindo o vetor ordenado
    printArray(arr, "Vetor ordenado");
    
    return 0;
}
