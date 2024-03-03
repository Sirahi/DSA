#pragma once

#include <map>

template <typename T>
struct NodeLRU
{
    NodeLRU(const T& in_value)
        : value(in_value), prev(nullptr), next(nullptr)
    {
    }

    ~NodeLRU()
    {
        prev = nullptr;
        next = nullptr;
    }

    T value;
    NodeLRU* prev;
    NodeLRU* next;
};

template <typename K, typename V>
class LRU
{
public:
    LRU(size_t capacity = 10)
        : m_capacity(capacity)
    {
    }

    void update(const K& key, const V& value)
    {
        NodeLRU<V>* node = m_lookup[key];

        if (!node)
        {
            node = new NodeLRU<V>(value);
            ++this->m_length;
            this->prepend(node);
            this->trimCache();
            this->m_lookup.insert_or_assign(key, node);
            this->m_reverseLookup.insert_or_assign(node, key);
        }
        else
        {
            this->detach(node);
            this->prepend(node);
            node->value = value;
        }
    }

    V get(const K& key)
    {
        NodeLRU<V>* node = m_lookup[key];

        if (!node)
        {
            return NULL;
        }

        this->detach(node);
        this->prepend(node);

        return node->value;
    }

private:
    void prepend(NodeLRU<V>* node)
    {
        if (!this->head)
        {
            this->head = this->tail = node;
            return;
        }

        node->next = this->head;
        this->head->prev = node;
        this->head = node;
    }

    void detach(const NodeLRU<V>* node)
    {
        if (node->next)
        {
            node->next->prev = node->prev;
        }

        if (node->prev)
        {
            node->prev->next = node->next;
        }

        if (this->head == node)
        {
            this->head = this->head->next;
        }

        if (this->tail == node)
        {
            this->tail = this->tail->prev;
        }
    }

    void trimCache()
    {
        if (m_length <= m_capacity)
        {
            return;
        }

        NodeLRU<V>* tail = this->tail;

        this->detach(tail);

        const K& key = this->m_reverseLookup[tail];

        this->m_lookup.erase(key);
        this->m_reverseLookup.erase(tail);

        --this->m_length;

        delete tail;
    }

    size_t m_capacity = 0;
    size_t m_length = 0;

    NodeLRU<V>* head = nullptr;
    NodeLRU<V>* tail = nullptr;

    std::map<K, NodeLRU<V>*> m_lookup = {};
    std::map<NodeLRU<V>*, K> m_reverseLookup = {};
};
