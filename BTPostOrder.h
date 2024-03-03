#pragma once

#include "Node.h"

#include <vector>

class BTPostOrder
{
public:
    template<typename T>
    static std::vector<T> order(const BinaryNode<T>* head)
    {
        std::vector<T> path = {};
        traverse(head, path);
        return path;
    }

private:
    template<typename T>
    static void traverse(const BinaryNode<T>* node, std::vector<T>& path)
    {
        if(node == nullptr)
        {
            return;
        }

        traverse(node->left, path);
        traverse(node->right, path);
        path.emplace_back(node->value);
    }
};
