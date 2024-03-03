#pragma once

#include <vector>

class QuickSort
{
public:
    template<typename T>
    static void  sort(T array[], size_t size)
    {
        qs(array, 0, size - 1);
    }

private:
    template<typename T>
    static void qs(T array[], const size_t lo, const size_t hi)
    {
        if(lo >= hi)
        {
            return;
        }

        const size_t pivotIdx = partition(array, lo, hi);
        
        qs(array, lo, pivotIdx - 1);
        qs(array, pivotIdx + 1, hi);
    }

    template<typename T>
    static size_t partition(T array[], const size_t lo, const size_t hi)
    {
        const T pivot = array[hi];

        size_t idx = lo - 1;

        for(size_t i = lo; i < hi; i++)
        {
            if(array[i] <= pivot)
            {
                idx++;
                T tmp = array[i];
                array[i] = array[idx];
                array[idx] = tmp;
            }
        }

        idx++;
        array[hi] = array[idx];
        array[idx] = pivot;

        return idx;
    }
};
