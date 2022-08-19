#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    Node(T val) : mVal(val) {}
    T Val() { return mVal; }
    T mVal;
    Node<T>* left {nullptr};
    Node<T>* right {nullptr};

    void Add(T t)
    {
        (t < mVal) ? Add(t, left) : Add(t, right);
    }

    void Add(T t, Node<T>*& node)
    {
        if (node)
        {
            node->Add(t);
        }
        else
        {
            node = new Node<T>(t);
        }
    }

    uint32_t Depth()
    {
        return 1 + std::max(Depth(left), Depth(right));
    }

    uint32_t Depth(Node<T>* node)
    {
        if (node == nullptr)
            return 0;
        return node->Depth();
    }

    void Print()
    {
//        printf();
    }
};

template <class T>
class BinaryTree
{
public:
    void Add(T t)
    {
        if (mRoot == nullptr)
        {
            mRoot = new Node<T>(t);
        }
        else
        {
            mRoot->Add(t);
        }
    }
    uint32_t Depth()
    {
        if (mRoot == nullptr) return 0;
        return mRoot->Depth();
    }


    void Print()
    {
        if (mRoot == nullptr) printf("NULL\n");
        mRoot->Print();
    }
private:

    Node<T>* mRoot {nullptr};
};

int main()
{
    BinaryTree<int> tree;
    tree.Add(5);

    std::cout << tree.Depth() << std::endl;

    tree.Add(4);
    std::cout << tree.Depth() << std::endl;

    tree.Add(3);
    std::cout << tree.Depth() << std::endl;

    return 0;
}
