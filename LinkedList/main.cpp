#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T val;
    Node<T>* next;
};

template <class T>
Node<T>* CreateList(T arr[], uint32_t size)
{
    Node<T>* head = nullptr;
    Node<T>** current = &head;
    for (int i = 0; i < size; ++i)
    {
        *current = new  Node<T>;
        (*current)->val = arr[i];
        (*current)->next = nullptr;
        current = &((*current)->next);
    }
    return head;
}

template <class T>
Node<T>* Last(Node<T>* list)
{
    Node<T>* current = list;
    while (current && current->next)
    {
        current = current->next;
    }
    return current;
}

template <class T>
Node<T>* Reverse(Node<T>* list)
{
    if (list == nullptr || list->next == nullptr)
    {
        return list;
    }

    Node<T>* reversed = Reverse(list->next);
    Last(reversed)->next = list;
    list->next = nullptr;

    return reversed;
}

template <class T>
Node<T>* Reverse2(Node<T>* list)
{
    Node<T>* current = list;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

template <class T>
void PrintList(Node<T>* list)
{
    Node<T>* current = list;
    while (current)
    {
        std::cout << current->val <<" ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    int64_t data[] = {3, 7, 6, 1, 0, 9, 4};
    int n = sizeof(data) / sizeof(data[0]);

    auto* list = CreateList(data, n);
    PrintList(list);

    auto* reversed = Reverse2(list);
    PrintList(reversed);
}
