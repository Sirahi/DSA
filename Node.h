#pragma once

#include <utility>

template<typename T>
struct Node
{
    T value;
    Node* next;

    Node(const T& in_value)
        : value(in_value), next(nullptr)
    {}

    Node(T&& in_value)
        : value(std::move(in_value)), next(nullptr)
    {}

    ~Node()
    {
        next = nullptr;
    }
};

template<typename T>
struct BinaryNode
{
    T value;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(T inValue)
        : value(inValue), left(nullptr), right(nullptr)
    {}

    ~BinaryNode()
    {
        left = nullptr;
        right = nullptr;
    }

    // bool operator==(BinaryNode& other)
    // {
    //     return this->value == other.value && this->left == other.left && this->right == other.right;
    // }
};
