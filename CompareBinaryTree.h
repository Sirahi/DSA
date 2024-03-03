#pragma once

#include "Node.h"

class CompareBinaryTree
{
public:
    template<typename T>
    static bool compare(const BinaryNode<T>* a, const BinaryNode<T>* b)
    {
        if(a == nullptr && b == nullptr)
        {
            return true;
        }

        if(a == nullptr || b == nullptr)
        {
            return false;
        }

        if(a->value != b->value)
        {
            return false;
        }

        return compare(a->left, b->left) && compare(a->right, b->right);
    }
};
