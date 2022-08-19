#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T val;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
Node<T>* CreateList(T arr[], uint32_t size)
{
    Node<T>* head = nullptr;
    Node<T>* previous = nullptr;
    Node<T>** current = &head;
    for (int i = 0; i < size; ++i)
    {
        *current = new  Node<T>;
        (*current)->prev = previous;
        (*current)->val = arr[i];
        (*current)->next = nullptr;
        previous = (*current);
        current = &((*current)->next);
    }
    return head;
}

template <class T>
Node<T>* Reverse2(Node<T>* list)
{
    Node<T>* current = list;
    Node<T>* temp = nullptr;
    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    return temp->prev;
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
    if (list == nullptr)
    {
        return list;
    }
    if (list->next == nullptr)
    {
        list->prev = nullptr;
        return list;
    }

    Node<T>* reversed = Reverse(list->next);
    Node<T>* last = Last(reversed);

    last->next = list;
    list->prev = last;

    list->next = nullptr;

    return reversed;
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

template <class T>
void PrintListRev(Node<T>* list)
{
    Node<T>* current = Last(list);
    while (current)
    {
        std::cout << current->val <<" ";
        current = current->prev;
    }
    std::cout << std::endl;
}

int main()
{
    int64_t data[] = {3, 7, 6, 1, 0, 9, 4};
    int n = sizeof(data) / sizeof(data[0]);

    auto* list = CreateList(data, n);
    PrintList(list);
    PrintListRev(list);
    std::cout << "----------------------\n";
    auto* reversed = Reverse2(list);
    PrintList(reversed);
    PrintListRev(reversed);
}
