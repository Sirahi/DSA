#pragma once
#include <vector>

class MergeSort
{
public:
    template<typename T>
    static void sort(std::vector<T>& array)
    {
        if(array.size() <=1)
        {
            return;
        }

        size_t mid = array.size() / 2;
        std::vector<T> left = std::vector<T>(array.begin(), array.begin() + mid);
        std::vector<T> right = std::vector<T>(array.begin() + mid, array.end());

        sort(left);
        sort(right);
        merge(array, left, right);
    }
private:
    template<typename T>
    static void merge(std::vector<T>& array, const std::vector<T>& left, const std::vector<T>& right)
    {
        size_t l = 0 , r = 0, i = 0;

        while(l < left.size() && r < right.size())
        {
            if(left[l] < right[r])
            {
                array[i] = left[l];
                l++;
            }
            else
            {
                array[i] = right[r];
                r++;
            }
            i++;
        }

        while (l < left.size())
        {
            array[i] = left[l];
            l++;
            i++;
        }

        while (r < right.size())
        {
            array[i] = right[r];
            r++;
            i++;
        }
    }
};

class MergeSortSmart
{
public:
    template<typename T>
    static void sort(T array[], const size_t begin, const size_t end)
    {
        if(begin >= end)
        {
            return;
        }

        const size_t mid = begin + (end - begin) / 2;

        sort(array, begin, mid);
        sort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
private:
    template<typename T>
    static void merge(T array[], const size_t begin, const size_t mid, const size_t end)
    {
        const size_t sizeL = mid - begin + 1;
        const size_t sizeR = end - mid;

        auto* left = new T[sizeL];
        auto* right = new T[sizeR];

        for (size_t i = 0; i < sizeL; i++)
            left[i] = array[i + begin];
        for (size_t j = 0; j < sizeR; j++)
            right[j] = array[j + mid + 1];

        size_t l = 0;
        size_t r = 0;
        size_t a = begin;

        while(l < sizeL && r < sizeR)
        {
            if(left[l] < right[r])
            {
                array[a] = left[l];
                l++;
            }
            else
            {
                array[a] = right[r];
                r++;
            }
            a++;
        }

        while (l < sizeL)
        {
            array[a] = left[l];
            l++;
            a++;
        }

        while (r < sizeR)
        {
            array[a] = right[r];
            r++;
            a++;
        }

        delete[] left;
        delete[] right;
    }
};
