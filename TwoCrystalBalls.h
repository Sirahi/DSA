#pragma once

#include <vector>

class TwoCrystalBalls
{
public:
    static int64_t TwoCrystalBallsImpl(const std::vector<bool>& breaks)
    {
        const size_t jumpAmount = sqrt(static_cast<double>(breaks.size()));

        size_t i = 0;
        for(; i < breaks.size(); i += jumpAmount)
        {
            if(breaks[i])
            {
                break;
            }
        }

        i -= jumpAmount;

        for(size_t j = 0; j <= jumpAmount && i < breaks.size(); j++, i++)
        {
            if(breaks[i])
            {
                return static_cast<int64_t>(i);
            }
        }

        return -1;
    }
};
