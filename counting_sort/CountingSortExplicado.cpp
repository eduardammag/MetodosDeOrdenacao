#include <iostream>
#include <vector>
#include <algorithm>

// Função para imprimir o estado atual do vetor
void printArray(const std::vector<int>& arr, const std::string& msg) {
    std::cout << msg << ": ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void countingSortVerbose(std::vector<int>& arr) {
    // Encontrar o maior valor no vetor
    int max_val = *std::max_element(arr.begin(), arr.end());
    std::cout << "Maior valor no vetor: " << max_val << std::endl;

    // Criar um vetor de contagem com tamanho suficiente para armazenar contagens de 0 até max_val
    std::vector<int> count(max_val + 1, 0);
    printArray(count, "Vetor de contagem inicial");

    // Contar a ocorrência de cada elemento no vetor original
    for (int num : arr) {
        count[num]++;
        printArray(count, "Incrementando count[" + std::to_string(num) + "]");
    }

    // Modificar o vetor de contagem para armazenar as posições dos elementos na saída
    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
        printArray(count, "Atualizando count[" + std::to_string(i) + "]");
    }

    // Criar um vetor de saída que será ordenado
    std::vector<int> output(arr.size(), 0);
    printArray(output, "Vetor de saída inicial");

    // Construir o vetor de saída
    for (int i = arr.size() - 1; i >= 0; i--) {
        int num = arr[i];
        output[count[num] - 1] = num;
        count[num]--;
        printArray(output, "Colocando " + std::to_string(num) + " na posição " + std::to_string(count[num]));
        printArray(count, "Decrementando count[" + std::to_string(num) + "]");
    }

    // Copiar o vetor de saída para o vetor original
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
        printArray(arr, "Copiando de volta para arr[" + std::to_string(i) + "]");
    }
}

int main() {
    // Definindo o vetor original
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    printArray(arr, "Vetor original");
    
    // Chamando a função de Counting Sort com verbose
    countingSortVerbose(arr);
    
    // Imprimindo o vetor ordenado
    printArray(arr, "Vetor ordenado");
    
    return 0;
}
