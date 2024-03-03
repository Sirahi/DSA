#pragma once

#include "Node.h"

template<typename T>
class Queue
{
public:
    ~Queue()
    {
        const Node<T>* node = this->head;

        while (node)
        {
            const Node<T>* nodeToDelete = node;
            node = node->next;
            delete nodeToDelete;
        }
    }
    
    void enqueue(const T& value)
    {
        Node<T>* node = new Node<T>(value); 

        if(m_length == 0)
        {
            this->head = this->tail = node;
        }
        else
        {
            this->tail->next = node;
            this->tail = node;
        }

        m_length++;
    }

    void enqueue(T&& value)
    {
         Node<T>* node = new Node<T>(std::move(value)); 

        if(m_length == 0)
        {
            this->head = this->tail = node;
        }
        else
        {
            this->tail->next = node;
            this->tail = node;
        }

        m_length++;
    }

    T dequeue()
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

    size_t length() const { return m_length; }

private:
    size_t m_length = 0;
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
};
