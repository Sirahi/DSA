#pragma once

#include "Node.h"

template<typename T>
class LinkedList
{
public:
    LinkedList(const T& value)
    {
        Node<T>* node = new Node<T>(value);
        head = tail = node;
        m_length++;
    }

    LinkedList(T&& value)
    {
        Node<T>* node = new Node<T>(std::move(value));
        head = tail = node;
        m_length++;
    }

    LinkedList& operator=(const LinkedList& other)
    {
        const LinkedList Temp = *this;
        *this->head = *(other.head);
        *this->tail = *(other.tail);
        this->m_length = other.m_length;

        return *this;
    }

    ~LinkedList()
    {
        const Node<T>* node = head;
        while (node)
        {
            const Node<T>* nodeToDelete = node;
            node = node->next;
            delete nodeToDelete;
        }
    }

    void inserAt(const size_t index, T&& value)
    {
        size_t i = 0;

        size_t pos = std::max((size_t)0, std::min(index, m_length));

        // inset at head
        if(pos == 0)
        {
            Node<T>* newNode = new Node<T>(std::move(value));
            newNode->next = head;
            head = newNode;
            m_length++;
            return;
        }

        // inset at tail
        if(pos == m_length)
        {
            Node<T>* newNode = new Node<T>(value);
            tail->next = newNode;
            tail = newNode;
            m_length++;
            return;
        }

        Node<T>* node = head;

        // insert in between
        while (--pos > 0)
        {
            node = node->next;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = node->next;
        node->next = newNode;
        m_length++;
    }

    void remove(const T& value)
    {
        Node<T>* prevNode = head;
        Node<T>* node = head;
        while (node && node->value != value)
        {
            prevNode = node;
            node = node->next;
        }

        if(node)
        {
            prevNode->next = node->next;
            m_length--;
            delete node;
        }
    }

    T removeAt(const size_t index)
    {
        size_t i = 0;
        Node<T>* prevNode = head;
        Node<T>* node = head;

        while (i < index && node)
        {
            i++;
            prevNode = node;
            node = node->next;
        }

        if(node)
        {
            prevNode->next = node->next;
            const T value = node->value;
            delete node;
            m_length--;
            return value;
        }

        return NULL;
    }

    void append(T&& value)
    {
        Node<T>* node = new Node<T>(std::move(value));

        node->next = head;
        head = node;
        m_length++;
    }

    void prepend(T&& value)
    {
        Node<T>* node = new Node<T>(std::move(value));

        tail->next = node;
        tail = node;
        m_length++;
    }

    T get(size_t index)
    {
        size_t i = 0;
        Node<T>* node = head;

        while (i < index && node)
        {
            i++;
            node = node->next;
        }

        if(node)
        {
            return node->value;
        }

        return NULL;
    }

private:
    size_t m_length = 0;
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
};
