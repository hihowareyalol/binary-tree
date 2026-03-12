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
    DestroyTree(root);
}

template <class T>
TreeT<T>& TreeT<T>::operator=(const TreeT& otherTree)
{
    if (root == otherTree.root) //check if it's the same tree
    {
        return this;
    }

    DestroyTree(root);
    CopyHelper([&]root, otherTree.root);

    numNodes = otherTree.numNodes;
    return this;
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
    //clear out the queue
    while (!iterArr.empty())
    {
        iterArr.pop();
    }
    if (traverseOrder == IN_ORDER)
    {
        PlaceInOrder(root);
    }
    else if (traverseOrder == PRE_ORDER)
    {
        PlacePreOrder(root);
    }
    else
    {
        PlacePostOrder(root);
    }
}

template <class T>
T TreeT<T>::GetNextItem()
{
    T nextItem = iterArr.front();

    iterArr.pop();
    return nextItem;
}

template <class T>
void TreeT<T>::DestroyTree(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
}

template <class T>
void TreeT<T>::CopyHelper(Node*& thisTree, Node* otherTree)
{
    if (otherTree == nullptr)
    {
        thisTree = nullptr;
        return;
    }

    thisTree = new Node;
    thisTree->value = otherTree->value;
    CopyHelper(thisTree->left, otherTree->left);
    CopyHelper(thisTree->right, otherTree->right);
}

template <class T>
void TreeT<T>::PlacePreOrder(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    iterArr.push(node->value);
    PlacePreOrder(node->left);
    PlacePreOrder(node->right);

}

template <class T>
void TreeT<T>::PlacePostOrder(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    iterArr.push(node->value);
    PlacePostOrder(node->left);
    PlacePostOrder(node->right);
}

template <class T>
void TreeT<T>::PlaceInOrder(Node* node)
{
}
