//
// Created by we7289 on 2/18/2021.
//

#include <iostream>
#include "TreeT.h"

int main(void)
{
    TreeT<int> treeA;

    treeA.Add(5);
    treeA.Add(1);
    treeA.Add(10);
    treeA.Add(2);

    if (treeA.Contains(5))
    {
        std::cout << "Contains 5" << std::endl;
    }
    if (treeA.Contains(1))
    {
        std::cout << "Contains 1" << std::endl;
    }
    if (treeA.Contains(10))
    {
        std::cout << "Contains 10" << std::endl;
    }
    if (treeA.Contains(2))
    {
        std::cout << "Contains 2" << std::endl;
    }
    if (treeA.Contains(-12))
    {
        std::cout << "Contains -12" << std::endl;
    } else
    {
        std::cout << "Doesn't contain -12" << std::endl;
    }

    //TreeT<int> treeB;

    //treeB = treeA;

    TreeT<int>* tree = new TreeT<int>;

    tree->Add(5);
    tree->Add(1);
    tree->Add(10);
    tree->Add(2);

    tree->ResetIterator(IN_ORDER);
    for (int i = 0; i < tree->Size(); i++) {
        cout << tree->GetNextItem() << " ";
    }
    cout << endl;

    delete tree;

    return 0;
}