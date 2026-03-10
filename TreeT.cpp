#include "TreeT.h"

template <class T>
TreeT<T>::TreeT()
{
    root = nullptr;
    numNodes = 0;
}

template <class T>
TreeT<T>::~TreeT()
{
}

template <class T>
TreeT<T>& TreeT<T>::operator=(const TreeT& otherTree)
{
}

template <class T>
void TreeT<T>::Add(T value)
{
    Node* parent = nullptr;
    Node* currN = root;

    while (currN != nullptr)
    {
        if (value < currN->value)
        {
            parent = currN;
            currN = currN->left;
        }
        else if (value > currN->value)
        {
            parent = currN;
            currN = currN->right;
        }
        else
        {
            return;
        }
    }
    Node* newNode = new Node;
    newNode->value = value;
    if (parent == nullptr)
    {
        root = newNode;
    }
    else if (value > parent->value)
    {
        parent->right = newNode;
    }
    else
    {
        parent->left = newNode;
    }
    numNodes++;
}

template <class T>
void TreeT<T>::Remove(T value)
{

}

template <class T>
bool TreeT<T>::Contains(T value)
{
    Node* currN = root;

    while (currN != nullptr) {
        if (value < currN->value)
        {
            currN = currN->left;
        }
        else if (value > currN->value)
        {
            currN = currN->right;
        }
        else
        {
            return true;
        }
    }
    return false;
}

template <class T>
int TreeT<T>::Size()
{
    return numNodes;
}

template <class T>
void TreeT<T>::ResetIterator(Order traverseOrder)
{

}

template <class T>
T TreeT<T>::GetNextItem()
{

}