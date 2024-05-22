#include <cstdlib>

template <typename T>
Node<T>* createNode(T iPayload)
{
    Node<T>* temp = (Node<T>*)malloc(sizeof(Node<T>));
    temp->payload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

template <typename T>
void insertEnd(Node<T>** head, T iPayload)
{
    Node<T>* newNode = createNode(iPayload);

    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    Node<T>* temp = (*head);

    while (temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev = temp;
    temp->ptrNext = newNode;
}

template <typename T>
void displayList(Node<T>* node, std::ostream& os)
{
    if (node == nullptr)
    {
        os << "Lista vazia: Não é possível realizar displayList" << std::endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        os << "Meio ou Fim da Lista: Não é possível realizar displayList" << std::endl;
        return;
    }

    Node<T>* currentNode = node;

    while (currentNode != nullptr)
    {
        os << currentNode->payload << " ";
        currentNode = currentNode->ptrNext;
    }
    os << std::endl;
}

template <typename T>
void deleteNode(Node<T>** head, Node<T>* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        std::cout << "Não foi possível remover." << std::endl;
        return;
    }

    if (*head == ptrDelete) (*head) = ptrDelete->ptrNext;

    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    free(ptrDelete);
}

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

    *head = nullptr;
}

template <typename T>
void swapValue(T& value1, T& value2)
{
    T temp = value1;
    value1 = value2;
    value2 = temp;
}

template <typename T>
void bubbleSort(Node<T>* head, int length)
{
    Node<T>* currentNode;
    Node<T>* nextNode = nullptr;

    for (int i = 0; i < length - 1; ++i)
    {
        currentNode = head;

        while (currentNode->ptrNext != nextNode)
        {
            if (currentNode->payload > currentNode->ptrNext->payload)
                swapValue(currentNode->payload, currentNode->ptrNext->payload);

            currentNode = currentNode->ptrNext;
        }

        nextNode = currentNode;
    }
}

template <typename T>
void optimizedBubbleSort(Node<T>* head, int length)
{
    bool bUnordered = false;
    Node<T>* currentNode;
    Node<T>* nextNode = nullptr;

    for (int i = 0; i < length - 1; ++i)
    {
        bUnordered = false;
        currentNode = head;

        while (currentNode->ptrNext != nextNode)
        {
            if (currentNode->payload > currentNode->ptrNext->payload)
            {
                swapValue(currentNode->payload, currentNode->ptrNext->payload);
                bUnordered = true;
            }

            currentNode = currentNode->ptrNext;
        }

        if (!bUnordered)
            break;

        nextNode = currentNode;
    }
}
