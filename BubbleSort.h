#pragma once

#include <vector>

class BubbleSort
{
public:
    template<typename T>
    static void BubbleSortList(std::vector<T>& array)
    {
        for(size_t i = 0; i < array.size(); i++)
        {
            for(size_t j = 0; j < array.size() - 1 - i; j++)
            {
                if (array[j] > array[j+1])
                {
                    T temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
};
