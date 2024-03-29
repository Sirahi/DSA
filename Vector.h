﻿#pragma once
#include <vector>

template<typename T>
class Vector
{
public:
    Vector()
    {
        ReAlloc(2);
    }

    ~Vector()
    {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void PushBack(const T& value)
    {
        if(m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }

        m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T&& value)
    {
        if(m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }

        m_Data[m_Size] = std::move(value);
        m_Size++;
    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args)
    {
        if(m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }

        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    void PopBack()
    {
        if(m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear()
    {
        for(size_t i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }

        m_Size = 0;
    }

    size_t Size() const { return m_Size; }

    const T& operator[](size_t index) const
    {
        return m_Data[index];
    }

    T& operator[](size_t index)
    {
        return m_Data[index];
    }

private:
    void ReAlloc(size_t newCapacity)
    {
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        if(newCapacity < m_Size)
            m_Size = newCapacity;

        for(size_t i=0; i < m_Size; i++)
        {
            newBlock[i] = std::move(m_Data[i]);
            m_Data[i].~T();
        }

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
    
    T* m_Data = nullptr;

    size_t m_Size = 0;
    size_t m_Capacity = 0;
};
