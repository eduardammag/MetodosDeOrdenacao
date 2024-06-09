#include <iostream>
#include <cstdlib> // Necessário para o uso de malloc

using namespace std;

// Função para criar um novo nó com um valor fornecido
template <typename T>
Node<T>* createNode(T iPayload)
{
    Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}

// Função para exibir os elementos da lista
template <typename T>
void displayList(Node<T>* node, ostream& os = cout)
{
    if (node == nullptr)
    {
        os << "Lista vazia: Não é possível realizar displayList" << endl;
        return; // Sai da função se a lista estiver vazia
    }
    
    if (node->ptrPrev != nullptr)
    {
        os << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return; // Sai da função se o nó não for o primeiro na lista
    }
    
    Node<T>* currentNode = node;
     
    while (currentNode != nullptr)
    {
        os << currentNode->iPayload << " ";
        currentNode = currentNode->ptrNext;
    }
    os << endl;
}

// Função para inserir um novo nó no final da lista
template <typename T>
void insertEnd(Node<T>** head, T iPayload)
{
    Node<T>* newNode = createNode(iPayload); // Cria um novo nó com o valor fornecido
    
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
    
    Node<T>* temp = *head;
    
    // Percorre a lista até o fim
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;
    
    newNode->ptrPrev = temp;   // O novo nó aponta para o último nó da lista
    temp->ptrNext = newNode;   // O último nó da lista aponta para o novo nó
}

// Função para remover um nó específico da lista
template <typename T>
void deleteNode(Node<T>** head, Node<T>* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }
    
    // Se o nó a ser removido for o primeiro nó da lista, atualiza a cabeça da lista
    if (*head == ptrDelete) *head = ptrDelete->ptrNext;
    
    // Se o nó a ser removido não for o último nó da lista, atualiza o ponteiro do nó posterior ao nó a ser removido
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    
    // Se o nó a ser removido não for o primeiro nó da lista, atualiza o ponteiro do nó anterior ao nó a ser removido
    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    
    free(ptrDelete); // Libera a memória alocada para o nó a ser removido
}

// Função para deletar toda a lista
template <typename T>
void deleteList(Node<T>** head)
{
    Node<T>* current = *head;
    Node<T>* next;

    while (current != nullptr)
    {
        next = current->ptrNext;
        free(current);
        current = next;
    }

    *head = nullptr; // Atualiza a cabeça da lista para nullptr
}

// Função para trocar dois valores
template <typename T>
void swapValue(T& iValue_1, T& iValue_2)
{
    T iTemp = iValue_1;
    iValue_1 = iValue_2;
    iValue_2 = iTemp;
}
