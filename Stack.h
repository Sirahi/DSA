#pragma once

#include "Node.h"

template<typename T>
class Stack
{
public:
    ~Stack()
    {}

    void push(const T& value)
    {
        Node<T>* node = new Node<T>(value); 

        if(m_length == 0)
        {
            this->head = node;
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }

        m_length++;
    }

    void push(T&& value)
    {
        Node<T>* node = new Node<T>(std::move(value)); 

        if(m_length == 0)
        {
            this->head = node;
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }

        m_length++;
    }

    T pop()
    {
        if(!this->head)
        {
            return NULL;
        }

        m_length--;
        
        const Node<T>* node = this->head;
        this->head = this->head->next;

        const T value = node->value;

        delete node;
        
        return value;
    }

    T peek()
    {
        if(this->head)
        {
            return this->head->value;
        }

        return NULL;
    }

private:
    size_t m_length = 0;
    Node<T>* head = nullptr;
};
