#pragma once

#include "Strategy.h"

#include <random>
#include <array>
#include <numeric>



class ProbStrategy : public Strategy
{
private:
    std::mt19937 random;
    int prevHandValue = 0;
    int currentHandValue = 0;
    std::array<std::array<int, 3>, 3> history{ {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}} };

public:
    ProbStrategy(int seed) :
        random(seed)
    {
    }

    Hand nextHand() override
    {
        int bet = random() % getSum(currentHandValue);

        int handvalue = (bet < history[currentHandValue][0]) ?
            0 : (bet < history[currentHandValue][0] + history[currentHandValue][1]) ?
            1 :
            2;
        prevHandValue = currentHandValue;

        currentHandValue = handvalue;

        return Hand::getHand(handvalue);
    }

    void study(bool win) override
    {
        if (win)
            history[prevHandValue][currentHandValue]++;
        else
        {
            history[prevHandValue][(currentHandValue + 2) % 3]++;
            history[prevHandValue][(currentHandValue + 2) % 3]++;
        }
    }

private:
    int getSum(int hv)
    {
        return std::accumulate(history[hv].begin(), history[hv].end(), 0);
    }
};

