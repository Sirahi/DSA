#pragma once

#include <vector>

class BinarySearch
{
public:
    template<typename T>
    static bool BinarySearchList(const std::vector<T> haystack, T needle)
    {
        int lo = 0;
        int hi = haystack.size();

        while (lo < hi)
        {
            const int mid = lo + (hi-lo) / 2;
            const T value = haystack[mid];

            if (value == needle)
            {
                return true;
            }

            if (value > needle)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return false;
    }
};
