#pragma once
#include <vector>

template <typename T>
class MinHeap
{
public:
    void insert(const T& value)
    {
        this->m_data.push_back(value);
        this->heapifyUp(this->m_length);
        m_length++;
    }

    T del()
    {
        if (this->m_length == 0)
        {
            return NULL;
        }

        const T out = this->m_data[0];
        m_length--;

        if (this->m_length == 0)
        {
            this->m_data = {};
            return out;
        }

        this->m_data[0] = this->m_data[m_length];
        this->m_data.pop_back();
        this->heapifyDown(0);
        return out;
    }

    size_t length() const { return m_length; }

private:
    void heapifyDown(const size_t idx)
    {
        const size_t lIdx = this->leftChild(idx);
        const size_t rIdx = this->rightChild(idx);

        if (lIdx >= m_length)
        {
            return;
        }

        const T lValue = this->m_data[lIdx];

        T rValue = NULL;
        if (rIdx < m_length)
        {
            rValue = this->m_data[rIdx];
        }

        const T value = this->m_data[idx];

        if (rValue && rValue < lValue && rValue < value)
        {
            this->m_data[idx] = rValue;
            this->m_data[rIdx] = value;
            this->heapifyDown(rIdx);
        }

        if ((!rValue || lValue < rValue) && lValue < value)
        {
            this->m_data[idx] = lValue;
            this->m_data[lIdx] = value;
            this->heapifyDown(lIdx);
        }
    }

    void heapifyUp(const size_t idx)
    {
        if (idx == 0)
        {
            return;
        }

        const size_t p = this->parent(idx);
        const T pValue = this->m_data[p];
        const T value = this->m_data[idx];

        if (pValue > value)
        {
            this->m_data[idx] = pValue;
            this->m_data[p] = value;
            this->heapifyUp(p);
        }
    }

    size_t leftChild(const size_t idx)
    {
        return 2 * idx + 1;
    }

    size_t rightChild(const size_t idx)
    {
        return 2 * idx + 2;
    }

    size_t parent(const size_t idx)
    {
        return (idx - 1) / 2;
    }

    size_t m_length = 0;
    std::vector<T> m_data = {};
};
