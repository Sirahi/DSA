#pragma once
#include "Node.h"

template <typename T>
class BinarySearchTree
{
public:
    bool find(const BinaryNode<T>* node, const T& value)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->value == value)
        {
            return true;
        }

        if (node->value < value)
        {
            return find(node->right, value);
        }

        return find(node->left, value);
    }

    BinaryNode<T>* insert(BinaryNode<T>* node, const T& value)
    {
        if (node == nullptr)
        {
            return new BinaryNode<T>(value);
        }

        if (node->value < value)
        {
            if (node->right == nullptr)
            {
                node->right = new BinaryNode<T>(value);
                return node;
            }
            else
            {
                insert(node->right, value);
            }
        }
        else
        {
            if (node->left == nullptr)
            {
                node->left = new BinaryNode<T>(value);
                return node;
            }
            else
            {
                insert(node->left, value);
            }
        }

        return nullptr;
    }

    BinaryNode<T>* del(BinaryNode<T>* root, const T& value)
    {
        if (root->value > value)
        {
            root->left = del(root->left, value);
            return root;
        }

        if (root->value < value)
        {
            root->right = del(root->right, value);
            return root;
        }

        // if no child, delete the current root
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // if right child, delete the current root and send back its right child
        if (root->left == nullptr)
        {
            BinaryNode<T>* node = root->right;
            delete root;
            return node;
        }

        // if left child, delete the current root and send back its left child
        if (root->right == nullptr)
        {
            BinaryNode<T>* node = root->right;
            delete root;
            return node;
        }

        // if both child exists
        BinaryNode<T>* parent = root;
        BinaryNode<T>* node = root->left;

        while (node->right != nullptr)
        {
            parent = node;
            node = node->right;
        }

        if (parent == root)
        {
            parent->left = node->left;
        }
        else
        {
            parent->right = node->left;
        }

        root->value = node->value;

        delete node;
        return root;
    }
};
